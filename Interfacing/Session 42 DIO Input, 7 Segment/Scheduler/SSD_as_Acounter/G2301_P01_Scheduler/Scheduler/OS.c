

#include "OS.h"


static OS_struct taskArray [MAX_NUM_OF_TASKS];
static u8 tasksCounter = 0;

OS_feedback OS_TaskCreate(fncPtr function, u8 periodicity, OS_state default_state)
{

	OS_feedback status = NOK_INIT;

	// Check ptr is not NULL
	if(function == NULLPTR)
	{
		status = NOK_NULL_PTR;
	}
	// Max Number of Tasks not exceeded
	else if(tasksCounter >= MAX_NUM_OF_TASKS)
	{
		status = NOK_TASK_COUNT_VIOLATION;
	}
	// Hyper period violation
	else if( periodicity > HYPER_PERIOD)
	{
		status = NOK_HYPER_PERIOD_VIOLATION;
	}
	else
	{
		// Create Task
		taskArray[tasksCounter].function = function;
		taskArray[tasksCounter].task_Periodicity = periodicity;
		taskArray[tasksCounter].task_state = default_state;
		taskArray[tasksCounter].Task_tick_counter = 1;
		// Increment # of created tasks
		tasksCounter++;
		status = OK;
	}
	return status;
}

/* LInked to ISR --- Time --- Task Ststes*/
void OS_Task_Handler(void)
{
	/*check each task timeout->ready : counter++*/
	u8 id=0;

	for(id=0;id<tasksCounter;id++){

		if(taskArray[id].task_state!=SUSPENDED){

		if(taskArray[id].Task_tick_counter>=taskArray[id].task_Periodicity){

				taskArray[id].task_state=READY;
				taskArray[id].Task_tick_counter=1;
			}
			else{

				taskArray[id].Task_tick_counter++;

			}
		}
	}




	/*
	u8 Task_Id;
	for(Task_Id = 0; Task_Id<taskCounter; Task_Id++)
	{
		if(taskArray[Task_Id].task_state != SUSPENDED)
		{
			// Check if the Task can be set to "Ready"
			if(taskArray[Task_Id].Task_tick_counter >= taskArray[Task_Id].task_Periodicity)
			{
				taskArray[Task_Id].task_state = READY;
				taskArray[Task_Id].Task_tick_counter = 1;
			}
			else
			{
				taskArray[Task_Id].Task_tick_counter++;
			}
		}
		else
		{
			// Nothing
		}
	*/

}


void OS_TaskExecution(void)
{
	u8 Task_Id;
	for(Task_Id = 0; Task_Id<tasksCounter; Task_Id++)
	{
		if(taskArray[Task_Id].task_state == READY)
		{
			taskArray[Task_Id].function();
			taskArray[Task_Id].task_state = BLOCKED;
		}
	}
}
