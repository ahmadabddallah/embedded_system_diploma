/*
 * Tasks.h
 *
 *  Created on: May 7, 2021
 *      Author: Zack
 */

#ifndef MY_TASKS_H_
#define MY_TASKS_H_

#include "semphr.h"

#define  TASK1_PRIORITY (3)
#define  TASK2_PRIORITY (2)
#define  TASK3_PRIORITY (2)

extern xSemaphoreHandle semSynch;


void Task1_LcdUpdate(void*pvParamter);


void Task2_ButtonCheck(void*pvParamter);

void Task3_ReadUart(void*pvParamter);


#endif /* MY_TASKS_H_ */













/*

// Defining each Task Priority
#define  TASK1_PRIORITY (2) // 	Low
#define  TASK2_PRIORITY (3) // 	Medium
#define  TASK3_PRIORITY (4) //	High

// Task  prototypes
 void Task1_LcdUpdate(void*pvParamter);
 void Task2_LcdUpdate(void*pvParamter);
 void Task3_Blink_L2(void*pvParamter);
 */
