/*
 * Tasks.c
 *
 *  Created on: May 7, 2021
 *      Author: Zack
 */


#include "Tasks.h"
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

#define  F_CPU  8000000UL
#include <util/delay.h>


void Task_1S_LcdUpdate(void)
{
	static u16 u16Seconds = 1;
	LCD_GoTo(0,10);
	LCD_WriteNumber(u16Seconds);
	u16Seconds++;

}

void Task_2S_Blink(void)
{
	DIO_TogglePin(PINB0);
}


void Task_3S_Blink(void)
{
	DIO_TogglePin(PINB2);
}


void print_forward(void){
	int pos=1;

	while(pos<=0x80){
		PORTB=pos;
		pos=pos<<1;
		_delay_ms(100);
	}

}

void print_reverse(void){
	int pos=0x80;
	while(pos>0){
		PORTB=pos;
		pos=pos>>1;
		_delay_ms(100);
	}

}
