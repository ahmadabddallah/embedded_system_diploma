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





int main(){
	
	
	
	DIO_Init();
	LCD_Init();
	KEYPAD_Init();
	UART_Init();
	
	sei();
	ADC_Init(VREF_AVCC,ADC_SCALER_64);
	
	DIO_WritePin(PINC0,LOW);
	DIO_WritePin(PINC1,LOW);
	DIO_WritePin(PINC2,LOW);
	

	volatile u16 Temp_read=0;
	
	u16 ldr_light=0;
	
	u8 y=0;
	
	while(1){
		
		/*LM35 Sesnor*/
		LCD_GoTO(0,0);
		Temp_read=TEMP_Read();
		LCD_WriteNumber(Temp_read);
		
		LCD_GoTO(0,0);
		Temp_read=ADC_Read(CH_7);
		Temp_read=((u32)Temp_read*5000/1023);
		LCD_WriteNumber(Temp_read);
		LCD_WriteString("    ");	
		
		/* implement the light due to LDR
		LCD_GoTO(0,5);
		ldr_light=ADC_Read(CH_0);
		LCD_WriteNumber(ldr_light);
		LCD_WriteString("    ");
		LCD_GoTO(1,10);*/
		LCD_WriteNumber(y++);
		if(y==10)
		y=0;
		
		//LCD_WriteString("second");
		/*LCD_GoTO(0,0);   fire system
		
		temp=TEMP_Read();
		temp_real=temp/10;
		temp_fixed=temp%10;
		
		
		
		if(temp_real<50 &&hystersis==0&&non_reversable==0){
			LCD_GoTO(0,5);
			LCD_WriteString("Fine");
			LCD_GoTO(1,0);
			LCD_WriteNumber(temp_real);
			LCD_WriteChar('.');
			LCD_WriteNumber(temp_fixed);
			LCD_WriteString("      ");	
			
			DIO_WritePin(PINC0,HIGH);
			DIO_WritePin(PINC1,LOW);
			DIO_WritePin(PINC2,LOW);
			
		}
		else if(temp_real>42&&non_reversable==0){
			hystersis=1;
			if(temp_real>42 &&temp_real<=45){
				hystersis=0;
				continue;
			}
			
			LCD_GoTO(0,5);
			LCD_WriteString("Heat");
			LCD_GoTO(1,0);
			LCD_WriteNumber(temp_real);
			LCD_WriteChar('.');
			LCD_WriteNumber(temp_fixed);
			LCD_WriteString("      ");
			
			DIO_WritePin(PINC0,LOW);
			DIO_WritePin(PINC1,HIGH);
			DIO_WritePin(PINC2,LOW);
			
			//read smoke sensor
			
			if(smoke_read>50){
				non_reversable=1;
				
				LCD_GoTO(0,5);
				LCD_WriteString("Fire");
				LCD_GoTO(1,0);
				LCD_WriteNumber(temp_real);
				LCD_WriteChar('.');
				LCD_WriteNumber(temp_fixed);
				LCD_WriteString("      ");
				
				DIO_WritePin(PINC0,LOW);
				DIO_WritePin(PINC1,LOW);
				DIO_WritePin(PINC2,HIGH);
				
				//motor on
				
			}
			
		}
		//LCD_WriteNumber(temp);
		
		//adding filter
		*/
		
	}
	

	
	
}

