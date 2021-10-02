/*
 * spi_master_task.c
 *
 *  Created on: Oct 2, 2021
 *      Author: lth
 */

#include <stdio.h>

#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os2.h"
#include "spi_master_task.h"

const osThreadAttr_t spiMasterTask_attributes = {
		.name = "spiMasterTask",
		.stack_size = 256 * 4,
		.priority = (osPriority_t) osPriorityLow,
};

osThreadId_t spiMasterTaskHandle;

void startSpiMasterTask(void *argument) {

	for (;;) {

		osDelay(1000);

		DBG("SPI Master");

	}

}
