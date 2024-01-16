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

u8 rec_data=0;
u8 data=0;
void Send_Rec_Async(void){
	
	rec_data=SPI_Receive_NoBlock();
	
}

int main(){
	
	DIO_Init();
	LCD_Init();
	SPI_Init();
	ADC_Init(VREF_AVCC,ADC_SCALER_64);
	LCD_WriteString("Slave");
	u16 Temp_value=0;
	LCD_WriteString("   ");
	SPI_SetCallBack(Send_Rec_Async);
	SPI_Interrupt_Enable();
	sei();
	
	
	
	while(1){
		LCD_GoTO(1,0);
		Temp_value=TEMP_Read();
		LCD_WriteNumber(Temp_value/10);
		LCD_WriteString("C");
		LCD_WriteString("     ");
		
		data=Temp_value/10;
		SPI_SendNoBlock(data);
	
		LCD_GoTO(1,7);
		LCD_WriteChar(rec_data);
		
		if(data>50){
			DIO_WritePin(PINB3,HIGH);
			_delay_ms(1);
			DIO_WritePin(PINB3,LOW);
			
		}
		
		
		
	}
		
}


