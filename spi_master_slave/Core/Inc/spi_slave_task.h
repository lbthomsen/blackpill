/*
 * spi_slave_task.h
 *
 *  Created on: Oct 2, 2021
 *      Author: lth
 */

#ifndef INC_SPI_SLAVE_TASK_H_
#define INC_SPI_SLAVE_TASK_H_

extern const osThreadAttr_t spiSlaveTask_attributes;

extern osThreadId_t spiSlaveTaskHandle;

void startSpiSlaveTask(void *argument);

#endif /* INC_SPI_SLAVE_TASK_H_ */
