#define  F_CPU  8000000UL
#include <util/delay.h>
#include "MemMap.h"
#include "StdTypes.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "LCD.h"
#include "KeyPad.h"
#include "ADC.h"
#include "Sensors.h"
#include "EXInterrupt.h"
#include "Timers.h"
#include "TimerServices.h"
#include "servo.h"
#include "ultrasonic.h"
#include "UART_Services.h"
#include "UART.h"
#include "SPI.h"
//slave
#include "OS.h"
#include "Tasks.h"


// ISR Callback
void vMillisIncrement(void)
{
	/*Shall be called every 100uSec*/
	/*1 mSec=100uSec*/
	static u16 u16_100uSecCounter = 0;
	static u16 u16_millisCounter = 0;
	u16_100uSecCounter++;

	if(u16_100uSecCounter >= 10)
	{
		/*reached 1 mSec*/
		u16_100uSecCounter = 0;
		u16_millisCounter++;
	}

	if(u16_millisCounter >= 1000)
	{
		// To be called every 1 Sec
		OS_Task_Handler();
		// Reset u16_millisCounter
		u16_millisCounter = 0;
	}

}


void vInitEcu(void)
{
	u8 str[] = {"Seconds: "};
	Timer0_Init(TIMER0_NORMAL_MODE, TIMER0_SCALER_8, OCO_DISCONNECTED);
	Timer0_OV_InterruptEnable();
	Timer0_OC_SetCallBack(vMillisIncrement);

	sei();
	DIO_Init();
	DIO_InitPin(PINB0,OUTPUT);
	DIO_InitPin(PINB2,OUTPUT);

	DIO_WritePin(PINB0,LOW);
	DIO_WritePin(PINB2,LOW);



	LCD_Init();
	LCD_WriteString(str);

}


void InitScheduler(void)
{
	/*Timer0_Init(TIMER0_NORMAL_MODE, TIMER0_SCALER_8, OCO_DISCONNECTED);
	Timer0_OV_InterruptEnable();
	Timer0_OC_SetCallBack(vMillisIncrement);
	*/
	//OS_TaskCreate(Task_1S_LcdUpdate,1,BLOCKED);
	/*
	OS_TaskCreate(Task_2S_Blink,2,BLOCKED);
	OS_TaskCreate(Task_3S_Blink,3,BLOCKED);
	*/
	OS_TaskCreate(print_forward,1,BLOCKED);

	OS_TaskCreate(print_reverse,1,BLOCKED);

}



int main(void)
{
	// Sw initilaization
	vInitEcu();

	// Start the Scheduler
	InitScheduler();

	while(1)
	{
		// Execute the scheduler
		OS_TaskExecution();
	}	
}



