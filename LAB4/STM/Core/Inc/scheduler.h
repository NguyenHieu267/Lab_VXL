/*
 * scheduler.h
 *
 *  Created on: Oct 26, 2025
 *      Author: hieun
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include "global.h"
#include "main.h"

typedef struct{
	void (*pTask)(void);
	uint32_t Delay;
	uint32_t Period;
	uint8_t  RunMe;

	uint32_t TaskID;
}sTasks;

#define SCH_MAX_TASKS 40
#define NO_TASK_ID 0

void SCH_Init(void);

uint32_t SCH_Add_Task(void (*pfunction)(),
				   uint32_t DELAY,
				   uint32_t PREIOD);

void SCH_Update(void);

void SCH_Dispatch_Tasks(void);

void SCH_Delete_Task(const uint32_t TASK_INDEX);

#endif /* INC_SCHEDULER_H_ */
