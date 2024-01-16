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
#include "Stepper.h"
#include "Timers_Services.h"
#include "Servo.h"
#include "SSD_Interface.h"
#include "state.h"

u8 data='A',rec_data,fire_flag;

void immediately_fire(void){
	LCD_GoTO(1,0);
	LCD_WriteString("flag");
	rec_data=SPI_SendReceive(data);
	data++;
	LCD_GoTO(1,7);
	LCD_WriteNumber(rec_data);
	LCD_WriteString("   ");
}

void interrupt_fire(void){
	fire_flag=1;	
}

int main(){
	
	DIO_Init();
	LCD_Init();
	SPI_Init();
	LCD_WriteString("Master");
	EXI_SetCallBack(EX_INT0,interrupt_fire);
	EXI_TriggerEdge(EX_INT0,RISING_EDGE);
	EXI_Enable(EX_INT0);
	sei();
	u8 first_button_flag=0,second_button_flag=0;
	
	while(1){
		LCD_GoTO(1,8);
		
		if(DIO_ReadPin(PINB0)==0){
			
			if(first_button_flag==0){
				first_button_flag=1;
				immediately_fire();		
			}
		}
		
		else{
			first_button_flag=0;	
		}
		if(fire_flag==1){
			immediately_fire();
			fire_flag=0;
		}
			
		
			
		
	}
		
}


