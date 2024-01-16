
#ifndef OS_H_
#define OS_H_

#include "StdTypes.h"

typedef void (*fncPtr)(void);           /**< Function pointer for registering tasks. */

#define MAX_NUM_OF_TASKS            ((u8)3)
#define HYPER_PERIOD                ((u8)6)

typedef enum
{
	SUSPENDED,
	BLOCKED,
	READY
} OS_state;


/*Task Control Block*/
typedef struct
{
	/*Function*/
	fncPtr      function;
	OS_state    task_state;
	/*periodocity  and priority insured by creating task order*/
	u8          task_Periodicity;
	u8          Task_tick_counter;
} OS_struct;


typedef enum
{
	OK,
	NOK_HYPER_PERIOD_VIOLATION,
	NOK_TASK_COUNT_VIOLATION,
	NOK_NULL_PTR,
	NOK_INIT
} OS_feedback;

OS_feedback OS_TaskCreate(fncPtr function, u8 periodicity, OS_state default_state);

void OS_Task_Handler(void);

void OS_TaskExecution(void);


#endif /* OS_H_ */
