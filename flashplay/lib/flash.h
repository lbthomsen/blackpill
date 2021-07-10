/*
 * flash.h
 *
 *  Created on: Jun 22, 2021
 *      Author: lth
 */

#ifndef FLASH_H_
#define FLASH_H_

#include "stm32f4xx_hal.h"

void flash_initialize();
void flash_deinitialize();
void flash_erase(uint32_t sector);
uint8_t flash_write(volatile uint32_t* address, uint32_t *data, uint16_t size);

#endif /* FLASH_H_ */
