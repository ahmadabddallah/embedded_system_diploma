#include "MemMap.h" 
#include "StdTypes.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#define F_CPU 8000000
#include "util/delay.h"
#include "KEYPAD_Interface.h"
#include "ADC_Interface.h"
#include "Sensors_Interface.h"
#include "EX_Interrupt_Interface.h"
#include "Timers.h"
#include "EEPROM.h"
#include "EEPROM_Services.h"
#include "UART.h"
#include "UART_Services.h"
#include "SPI.h"
#include "Check_Password.h"
#include "ULTRASONIC.h"
#include "String.h"
#include "RGB.h"


int main(){
	
	DIO_Init();
	LCD_Init();
	KEYPAD_Init();
	ADC_Init(VREF_AVCC,ADC_SCALER_64);
	
	

	
	u16 adc_read=0;	
	u16 temp=0;
	u8 hystersis_Flag=0;
	u8 smoke_sensor_state=0;
	u8 non_reversible_flag=0;
	u8 reset_mode_flag=0;
	u8 key=NO_KEY;
	u8 saved_password[4]={0};
	u8 Idx_saved_password=0;	
	u8 pressed_password[4]={0};
	u8 Idx_pressed_password=0;
	

	/*u8 password_NVM="1234";
	EEPROM_StoreString_Sync(password_NVM);
	*/
	
	//copy password from eeprom to ram
	for(u8 i=0;i<4;i++){
		saved_password[i]=EEPROM_Read(i);
	}
	Idx_pressed_password=0;
	
	check_password_t state;
		while(1){
	
		key=KEYPAD_GetKey();
		if(key!=NO_KEY&&reset_mode_flag==0){
			reset_mode_flag=1;
			LCD_Clear();
			LCD_GoTO(0,3);
			LCD_WriteString("Password");
			//continue;
			
		}	
		if(reset_mode_flag==1&&key!=NO_KEY){
			
			if(key!='='){
				pressed_password[Idx_pressed_password++]=key;
			
				LCD_GoTO(1,Idx_pressed_password);
				LCD_WriteChar(key);
				_delay_ms(100);
				LCD_GoTO(1,Idx_pressed_password);
				LCD_WriteChar('*');
				/*
				_delay_ms(100);
				LCD_GoTO(1,Idx_pressed_password);
				LCD_WriteChar('*');
				*/
				continue;		
				}
				else{
					state= check_password(saved_password,pressed_password);
					if(state==CORRECT){
						LCD_Clear();
						LCD_WriteString("Correct");
						non_reversible_flag=0;
						reset_mode_flag=0;
						//motor turn of
						DIO_WritePin(PIND6,LOW);
						DIO_WritePin(PIND7,LOW);
						LCD_Clear();
						Idx_pressed_password=0;
					}
					else {
						LCD_Clear();
						
						LCD_WriteString("NOT Correct");
						LCD_Clear();
						LCD_GoTO(0,3);
						LCD_WriteString("Password");
						Idx_pressed_password=0;
					}
				}
		}
		
	
		if(reset_mode_flag==0)
		{
		adc_read=ADC_Read(CH_0);
		temp=TEMP_Read();
		
		
		if(smoke_sensor_state==1&&non_reversible_flag==0){
			
			LCD_GoTO(1,12);
			LCD_WriteString("S:");
			LCD_WriteNumber(adc_read);
			LCD_WriteString("    ");
		}
		LCD_GoTO(1,0);
		LCD_WriteString("T:");
		LCD_WriteNumber(temp/10);
		LCD_WriteChar('.');
		LCD_WriteNumber(temp%10);
		
		if(temp<500 &&hystersis_Flag==0&&non_reversible_flag==0){
			LCD_GoTO(0,7);
			LCD_WriteString("Fine");
			DIO_WritePin(PINB0,HIGH);
			DIO_WritePin(PINB1,LOW);
			DIO_WritePin(PINB2,LOW);
		}
		else if(temp>460&&non_reversible_flag==0){
			LCD_GoTO(0,7);
			LCD_WriteString("Heat");
			DIO_WritePin(PINB0,LOW);
			DIO_WritePin(PINB1,HIGH);
			DIO_WritePin(PINB2,LOW);
			smoke_sensor_state=1;
			hystersis_Flag=1;
			
		}
		else if(temp<460){
			hystersis_Flag=0;
			smoke_sensor_state=0;
		}
		if(smoke_sensor_state==1 &&adc_read>1000&&non_reversible_flag==0){
			LCD_GoTO(0,7);
			LCD_WriteString("Fire");
			//Motor on
			DIO_WritePin(PIND6,LOW);
			DIO_WritePin(PIND7,HIGH);
			
			//turn on led red
			DIO_WritePin(PINB0,LOW);
			DIO_WritePin(PINB1,LOW);
			DIO_WritePin(PINB2,HIGH);
			non_reversible_flag=1;
		}
	}
}
		}


