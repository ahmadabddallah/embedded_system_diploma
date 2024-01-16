/*
 * Tasks.h
 *
 *  Created on: May 7, 2021
 *      Author: Zack
 */

#ifndef SCHEDULER_TASKS_H_
#define SCHEDULER_TASKS_H_



void Task_1S_LcdUpdate(void);
void Task_2S_Blink(void);
void Task_3S_Blink(void);

/*DIO Tasks*/
/*Print array Forward*/
void print_forward(void);

void print_reverse(void);

#endif /* SCHEDULER_TASKS_H_ */
