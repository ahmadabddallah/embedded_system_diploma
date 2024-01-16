/*
 * Tasks.c
 *
 *  Created on: May 7, 2021
 *      Author: Zack
 */



#include <util/delay.h>
#include "MemMap.h"
#include "StdTypes.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "LCD.h"
#include "UART.h"

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


#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"
#include "semphr.h"
#include "MyTasks.h"


xSemaphoreHandle semSynch = NULL;



volatile u8 UART_Buffer[100]={0};
volatile u8 counter=0,i=0;

void Uart_Buffer (void){

	UART_Buffer[i]=UART_ReceiveNoBlock();
	counter++;
	i++;

}



void Task1_LcdUpdate(void*pvParamter)
{
	/*u8 Msg_Lcd[] 		= "T1";
	LCD_GoTo(0,0);
	LCD_WriteString(Msg_Lcd);
	u8 btn_Prsd[] 	 	= "Prs#";
	u8 counter = 0;
	 */

	while(1)
	{
		//  Take: wait for it to be available
		if(xSemaphoreTake(semSynch, portMAX_DELAY))
		{

			LCD_WriteString(UART_Buffer);
			i=0;
			counter=0;
			UART_Send('o');
			UART_Send('k');
			// Update LCD with pressing message
			/*
			DIO_TogglePin(PINB2_PR);
			LCD_GoTo(1,0);
			LCD_WriteString(btn_Prsd);
			LCD_GoTo(1,10);
			LCD_WriteNumber(counter);
			counter++;*/
		}
		else
		{
			//report error
		}
		vTaskDelay(2000);
	}
}


void Task2_ButtonCheck(void*pvParamter)
{
	//  Take
//	xSemaphoreTake(semSynch, (portTickType)0);

	while(1)
	{
		if( (DIO_ReadPin(PINA0_PR)) == LOW)
		{
	//		DIO_TogglePin(PINB0_PR);
			// Give
			xSemaphoreGive(semSynch);
			_delay_ms(100);
			DIO_TogglePin(PINB0_PR);
			_delay_ms(100);

		}
		else
		{
			//DIO_TogglePin(PINB2_PR);
		}
		vTaskDelay(200);
	}

}

void Task3_ReadUart(void*pvParamter){
	Set_RX_CallBack(Uart_Buffer);
	 RX_InterruptEnable();

	while(1){

		if(i>0){

			xSemaphoreGive(semSynch);

		}
		else{

		}
		/*

		if(UART_RecievePerodic(&data)){
			xSemaphoreGive(semSynch);

			DIO_TogglePin(PINB0_PR);


		}
		else
			{
				//DIO_TogglePin(PINB2_PR);
			}
			vTaskDelay(200);


	}*/
	}
}




// xSemaphoreHandle semSynch = NULL;


//  Take
//xSemaphoreTake(semSynch, portMAX_DELAY);
// Give
//xSemaphoreGive(semSynch);
