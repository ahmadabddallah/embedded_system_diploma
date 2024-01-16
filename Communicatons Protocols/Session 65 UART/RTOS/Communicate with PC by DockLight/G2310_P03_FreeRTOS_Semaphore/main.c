/*
 * RTOS_LAB1_ATMEGA32.c
 *
 * Created: 5/5/2021
 *  Author: Zack
 */

#define  F_CPU  8000000UL

#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"

#include "MemMap.h"
#include "StdTypes.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "LCD.h"
#include "UART.h"
#include "semphr.h"

//#include "KeyPad.h"
//#include "ADC.h"
//#include "Sensors.h"
//#include "EXInterrupt.h"
//#include "Timers.h"
//#include "TimerServices.h"
//#include "servo.h"
//#include "ultrasonic.h"
//#include "UART_Services.h"
//#include "UART.h"
//#include "SPI.h"

#include <MyTasks.h>




void vInitEcu(void)
{
	sei();
	DIO_Init();
	DIO_InitPin(PINB0_PR,OUTPUT);
	DIO_InitPin(PINB2_PR,OUTPUT);

	DIO_InitPin(PINA0_PR,INFREE);

	DIO_WritePin(PINB0_PR,LOW);
	DIO_WritePin(PINB0_PR,LOW);
	LCD_Init();
	UART_Init();



}




int main(void)
{
	vInitEcu();


	xTaskCreate(Task1_LcdUpdate, NULL, 250, NULL, TASK1_PRIORITY, NULL);
	//xTaskCreate(Task2_ButtonCheck, NULL, 250, NULL, TASK2_PRIORITY, NULL);
	xTaskCreate(Task3_ReadUart,NULL,250,NULL,TASK3_PRIORITY,NULL);
	vSemaphoreCreateBinary(semSynch);
	vTaskStartScheduler();

	while(1){};

	return 0;

}









// vSemaphoreCreateBinary(semSynch);

/*



	xTaskCreate(Task1_LcdUpdate,NULL,200,NULL,TASK1_PRIORITY,NULL);
	xTaskCreate(Task2_LcdUpdate,NULL,200,NULL,TASK2_PRIORITY,NULL);
	xTaskCreate(Task3_Blink_L2,NULL,100,NULL,TASK3_PRIORITY,NULL);


	vTaskStartScheduler();



*/
