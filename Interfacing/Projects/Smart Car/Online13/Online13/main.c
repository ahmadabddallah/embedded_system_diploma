#include "MemMap.h" 
#include "StdTypes.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#define F_CPU 8000000
#include "util/delay.h"
#include "KEYPAD_Interface.h"
#include "ADC_Interface.h"
#include "EX_Interrupt_Interface.h"
#include "Timers.h"
#include "UART.h"
#include "UART_Services.h"
#include "ULTRASONIC.h"
#include "String.h"
#include "MOTOR_Interface.h"
#include "Car.h"

volatile u8 flag=0;

volatile u8 temp=0;
void RX_func(void){
	temp=UART_ReceiveNoBlock();
	signal=temp;
	flag=1;
}
void LCD_dispaly(u8 signal);

int main(){
	
	DIO_Init();
	LCD_Init();
	MOTOR_Init();
	Car_Init();
	UART_Init();
	Timer1_Init(TIMER1_NORMAL_MODE,TIMER1_SCALER_8);
	TIMER0_Init(TIMER1_FASTPWM_ICR_TOP_MODE,TIMER0_SCALER_8);
	TIMER0_OC0Mode(OC0_NON_INVERTING);
	OCR0=125;
	
	sei();
	 
	u8 recieve_flag=0;
	while(1){
		
		Detection_Runnable();
		LCD_GoTO(0,0);
		LCD_WriteNumber(Detection_getStopFlag());
		recieve_flag=UART_RecievePerodic(&signal);
		CAR_Runnable();
		
		if(recieve_flag==1||Detection_getStopFlag()==1){
			LCD_dispaly(signal);
		}
			
		
	}
	
	

	
		
}

void LCD_dispaly(u8 signal){
	LCD_Clear();
	LCD_GoTO(0,3);
	switch (signal){
		
		case '1':
		LCD_WriteString("moveForward");
		break;
		case '2':
		LCD_WriteString("moveBackward");
		break;
		case '3':
		LCD_WriteString("moveRight");
		break;
		
		case'4':
		LCD_WriteString("moveLeft");
		break;
		
		case '5':
		LCD_WriteString("CAR STOP");
		break;
		
		case '6':
		LCD_GoTO(0,0);
		LCD_WriteString("Speed Mode : 1");
		break;
		
		case '7':
		LCD_GoTO(0,0);
		LCD_WriteString("Speed Mode : 2");
		break;
		
		case '8':
		LCD_GoTO(0,0);
		LCD_WriteString("Speed Mode : 3");
		break;

	}
}


