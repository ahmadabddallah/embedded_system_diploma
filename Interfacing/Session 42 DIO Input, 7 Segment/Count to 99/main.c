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

u8 counter=0;

int main(){
	
	DIO_Init();
	LCD_Init();
	
	LCD_WriteString("SSD");
	u16 pos=1;
	u8 y=0;
	while(1){
		for(u8 i=0;i<250;i++){
			SSD_SetNum(y);
			_delay_ms(1);
		
		}
		y++;
		if(y>=100){
			y=0;
		}
		DIO_WritePin(COM2,HIGH);
		DIO_WritePin(COM1,HIGH);
		_delay_ms(1000);
		
		
	}
		
}


