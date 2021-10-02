/*
 * debug.c
 *
 *  Created on: Oct 1, 2021
 *      Author: lth
 */

#include <stdio.h>

#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os2.h"
#include "status_task.h"

const osThreadAttr_t statusTask_attributes = {
		.name = "statusTask",
		.stack_size = 256 * 4,
		.priority = (osPriority_t) osPriorityLow,
};

osThreadId_t statusTaskHandle;

void startStatusTask(void *argument) {

	TaskStatus_t *pxTaskStatusArray;
	volatile UBaseType_t uxArraySize, x;
	unsigned long ulTotalRunTime;
	float runtime_percent;
	uint32_t rt_whole, rt_fract;

	for (;;) {
		osDelay(10000);

		uxArraySize = uxTaskGetNumberOfTasks();
		pxTaskStatusArray = pvPortMalloc(uxArraySize * sizeof(TaskStatus_t)); // a little bit scary!

		if (pxTaskStatusArray != NULL) {
			uxArraySize = uxTaskGetSystemState(pxTaskStatusArray, uxArraySize, &ulTotalRunTime);

			DBG("Task count = %lu", uxArraySize);
			DBG("No      Name          S Usage   HW");

			for (x = 0; x < uxArraySize; x++) {

				runtime_percent = (float)(100 * (float)pxTaskStatusArray[x].ulRunTimeCounter / (float)ulTotalRunTime);
				rt_whole = (uint32_t)runtime_percent;
				rt_fract = (uint32_t)(100 * (runtime_percent - rt_whole));

				DBG("Task %lu: %-12s %2d %2lu.%02lu %4i", x, pxTaskStatusArray[x].pcTaskName, pxTaskStatusArray[x].eCurrentState, rt_whole, rt_fract, pxTaskStatusArray[x].usStackHighWaterMark);

			}

			vPortFree(pxTaskStatusArray);

		} else {
			DBG("Unable to allocate stack space");
		}

	}

}
