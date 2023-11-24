#include "MemMap.h" 
#include "StdTypes.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#define F_CPU 8000000
#include "util/delay.h"
#include "Timers.h"
#include "Timers_Services.h"
#include "UART.h"
#include "UART_Services.h"
#include "GPS.h"
#include "GPS_Services.h"


int main(){
	
	DIO_Init();
	LCD_Init();
	UART_Init();
	
	sei();
	
	GPS_Init();
	
	u8 lat[50]={0};
	u8 lng[50]={0};
	
	
	Timer1_SetInterruptTime_s(5,updateGPS);
	u8 counter=0;
	
	while(1){
		
		GPS_get_lant_lag(lat,lng);
		UART_SendString_Async(lng);
		_delay_ms(100);
		UART_SendString_Async(lat);
		
		
		LCD_GoTO(1,10);
		
		LCD_WriteNumber(counter++);
		if(counter==10){
			counter=0;
		}
		LCD_WriteString("    ");
		
		
	}
	

	
	
}

