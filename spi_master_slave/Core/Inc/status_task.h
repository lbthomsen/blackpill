/*
 * status_task.h
 *
 *  Created on: Oct 1, 2021
 *      Author: lth
 */

#ifndef INC_STATUS_TASK_H_
#define INC_STATUS_TASK_H_

extern const osThreadAttr_t statusTask_attributes;

extern osThreadId_t statusTaskHandle;

void startStatusTask(void *argument);

#endif /* INC_STATUS_TASK_H_ */
