/*
 * spi_slave_task.c
 *
 *  Created on: Oct 2, 2021
 *      Author: lth
 */

#include <stdio.h>

#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os2.h"
#include "spi_slave_task.h"

const osThreadAttr_t spiSlaveTask_attributes = {
		.name = "spiSlaveTask",
		.stack_size = 256 * 4,
		.priority = (osPriority_t) osPriorityLow,
};

osThreadId_t spiSlaveTaskHandle;

void startSpiSlaveTask(void *argument) {

	for (;;) {

		osDelay(1000);

		DBG("SPI Slave");

	}

}

