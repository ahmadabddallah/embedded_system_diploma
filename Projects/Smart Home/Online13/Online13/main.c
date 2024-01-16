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


typedef enum{
	sign_in,
	log_in
	
}eeprom_read_t;

typedef enum{
	ON,
	OFF
	
}servo_mode_t;



void copy_EEPROM_to_Ram(u8 password_saved []);

void check_sign_or_login(eeprom_read_t state);

void check_condition(check_password_t chk);

void servo_mode(servo_mode_t);

eeprom_read_t state;
u8 flag=0;
int main(){
	
	DIO_Init();
	LCD_Init();
	KEYPAD_Init();
	//EEPROM_Erase();
	
	/*check if this setup for first time or just log on*/
	state=(EEPROM_Read(0)==0xff)?sign_in:log_in;
	
	u8 password_saved[4]={0};
	copy_EEPROM_to_Ram(password_saved);
	
	u8 x=NO_KEY;
	u8 password[4]={0};
	
	u8 idx_pass=0;	
	u8 lcd_idx=0;
	sei();
	
	volatile u16 distance=100;
	
	while(1){
		
		
		while(distance>15){
			distance=UltraSonic_GetRead_cm(PIND7);
			_delay_ms(60);//ultrasonic needs break at least 60 Us
		}
		
		x=KEYPAD_GetKey();
		if(flag==0)
		check_sign_or_login(state);
		if(state==sign_in){
			if((x>='0'&&x<='9') &&idx_pass<4){
				password[idx_pass++]=x;
				LCD_GoTO(1,lcd_idx);
				LCD_WriteChar(x);
				_delay_ms(100);
				LCD_GoTO(1,lcd_idx);
				LCD_WriteChar('*');
				lcd_idx++;	
			}
			if(x =='='){
				EEPROM_Write(EEPROM_CurrentAddress++,log_in);
				state=log_in;
				EEPROM_StoreString_Sync(password);
				idx_pass=0;
				LCD_Clear();
			}
		}
		else if(state==log_in){
			if(x>='0'&&x<='9'){
				password[idx_pass++]=x;
				LCD_GoTO(1,lcd_idx);
				LCD_WriteChar(x);
				_delay_ms(100);
				LCD_GoTO(1,lcd_idx);
				LCD_WriteChar('*');
				lcd_idx++;	
			}
			if(x == '='){
				check_password_t chk=check_password(password_saved,password);
				check_condition(chk);
				idx_pass=0;
				lcd_idx=0;
			}
		}
	}
	
	
}


void copy_EEPROM_to_Ram(u8 password_saved[]){
	for(u8 i=1,j=0;i<5;i++,j++){
		password_saved[j]=EEPROM_Read(i);
	}
}

void check_sign_or_login(eeprom_read_t state){
	flag=1;
	LCD_Clear();
	LCD_WriteString("Hello");
	LCD_GoTO(1,0);
	if(state==sign_in){
		LCD_Clear();
		LCD_WriteString("set a password");
	}

	else{
		LCD_WriteString("enter password ");
		LCD_Clear();
	}
}

void check_condition(check_password_t chk){
	
	if(chk==CORRECT){
		LCD_Clear();
		LCD_WriteString("Correct");
		servo_mode(ON);
	}
	else{
		static u8 no_of_tries=0;
		LCD_Clear();
		LCD_WriteString("NOT Correct");
		LCD_Clear();
		LCD_WriteString("wait 3");
		_delay_ms(100);
		LCD_GoTO(0,0);
		LCD_WriteString("wait 2");
		_delay_ms(100);
		LCD_GoTO(0,0);
		LCD_WriteString("wait 1");
		_delay_ms(100);
		LCD_Clear();
		
		no_of_tries++;
		if(no_of_tries==3){
			//send signal in GSM() that is thieve
			DIO_WritePin(PINA7,HIGH);
		}	
	}
}

void servo_mode(servo_mode_t mode){
	if(mode==ON){
		Timer1_Init(TIMER1_FASTPWM_OCRA_TOP_MODE,TIMER1_SCALER_8);
		Timer1_OCRB1Mode(OCRA_NON_INVERTING);
		OCR1A=19999;
		OCR1B=1499;
		_delay_ms(3000);
		LCD_Clear();
		OCR1B=999;
		
	}
	else if(mode==OFF){
		Timer1_OCRA1Mode(OCRA_NON_INVERTING);
		OCR1B=19999;
		OCR1A=499;	
	}
	
}