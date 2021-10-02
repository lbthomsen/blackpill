/*
 * spi_master_task.h
 *
 *  Created on: Oct 2, 2021
 *      Author: lth
 */

#ifndef INC_SPI_MASTER_TASK_H_
#define INC_SPI_MASTER_TASK_H_

extern const osThreadAttr_t spiMasterTask_attributes;

extern osThreadId_t spiMasterTaskHandle;

void startSpiMasterTask(void *argument);

#endif /* INC_SPI_MASTER_TASK_H_ */
