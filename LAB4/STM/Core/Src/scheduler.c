/*
 * scheduler.c
 *
 *  Created on: Oct 26, 2025
 *      Author: hieun
 */
#include "scheduler.h"


sTasks SCH_tasks_G[SCH_MAX_TASKS];
uint32_t time_point = 0;
char str[50];



void SCH_Init(void) {
	unsigned char i ;
	for (i = 0; i <SCH_MAX_TASKS; i++) {
		SCH_Delete_Task(i);
	}

//	Error_code_G= 0;
//	Timer_init();
//	Watchdog_init();
}

void SCH_Update(void){
	unsigned char Index;
	for (Index = 0; Index <SCH_MAX_TASKS; Index++) {
		if (SCH_tasks_G[Index].pTask){
			if (SCH_tasks_G[Index].Delay <= 1) {
				SCH_tasks_G[Index].RunMe++;
				if (SCH_tasks_G[Index].Period) {
				SCH_tasks_G[Index].Delay = SCH_tasks_G[Index].Period;
				}
			} else {
			SCH_tasks_G[Index].Delay -= 1;
			}
		}
	}
	time_point +=10;
}

void SCH_Dispatch_Tasks(void)
{
	unsigned char Index;

	for (Index = 0; Index <SCH_MAX_TASKS; Index++){
		if (SCH_tasks_G[Index].RunMe> 0) {
			(*SCH_tasks_G[Index].pTask)(); // Run the task
			sprintf(str, "TaskID: %ld toggle at time: %ld ms\r\n", SCH_tasks_G[Index].TaskID,time_point);
			writemessage(str);
			SCH_tasks_G[Index].RunMe--; // Reset / reduceRunMe flag
			if (SCH_tasks_G[Index].Period == 0)
			{
				SCH_Delete_Task(Index);
			}
		}
	}
//	SCH_Report_Status();
//	SCH_Go_To_Sleep();
}

uint32_t SCH_Add_Task(void (* pFunction) () , uint32_t DELAY, uint32_t PERIOD)
{
	unsigned char Index = 0;
	// First find a gap in the array (if there is one)
	while ((SCH_tasks_G[Index].pTask != 0) && (Index < SCH_MAX_TASKS))
	{
		Index++;
	}

//	if (Index ==SCH_MAX_TASKS)
//	{
//	Error_code_G=ERROR_SCH_TOO_MANY_TASKS;
//
//	return SCH_MAX_TASKS;
//	}

	SCH_tasks_G[Index].pTask = pFunction;
	SCH_tasks_G[Index].Delay =DELAY;
	SCH_tasks_G[Index].Period =PERIOD;
	SCH_tasks_G[Index].TaskID = Index;
	SCH_tasks_G[Index].RunMe= 0;

	return Index;
}

void SCH_Delete_Task(const uint32_t TASK_INDEX){

	SCH_tasks_G[TASK_INDEX].pTask = 0x0000;
	SCH_tasks_G[TASK_INDEX].Delay = 0;
	SCH_tasks_G[TASK_INDEX].Period = 0;
	SCH_tasks_G[TASK_INDEX].RunMe = 0;

}
