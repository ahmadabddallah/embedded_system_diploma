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
#include "Stack.h"

volatile u8 UART_Buffer[100]={0};
volatile u8 counter=0,i=0;

void Uart_Buffer (void){

	UART_Buffer[i]=UART_ReceiveNoBlock();
	counter++;
	i++;
}

void Receive_OnStack(void){
	volatile stackStatus_t st;
	static StackCounter=0;
	st=push(UART_ReceiveNoBlock());
	
	if(st==STACK_DONE){
		StackCounter++;
	}	
	
	
}

int main(){
	
	DIO_Init();
	LCD_Init();
	UART_Init();
	Set_RX_CallBack(Receive_OnStack);
	RX_InterruptEnable();
	sei();
	LCD_WriteString("stack");

	//stack_t* st= stack_create(10);
	LCD_GoTO(1,0);
	
	u8 x;
	
	
	u8 butto1_flag=0;
		
	while(1){
		if(DIO_ReadPin(PIND7)==0){
			if(butto1_flag==0){
				pop(&x);
				LCD_WriteChar(x);
				butto1_flag=1;
			}
		}
		else{
			butto1_flag=0;
		}

	}
		
}


