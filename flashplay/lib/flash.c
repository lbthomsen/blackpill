/*
 * flash.c
 *
 *  Created on: Jun 22, 2021
 *      Author: lth
 */

#include "flash.h"

void flash_initialize()
{
	HAL_FLASH_Unlock();
}

void flash_deinitialize()
{
	HAL_FLASH_Lock();
}

void flash_erase(uint32_t sector)
{
    uint32_t error = 0;
    FLASH_EraseInitTypeDef FLASH_EraseInitStruct =
    {
    	.TypeErase = FLASH_TYPEERASE_SECTORS,
	.Sector = (uint32_t)sector,
	.NbSectors = 1,
	.VoltageRange = FLASH_VOLTAGE_RANGE_3
    };

    HAL_FLASHEx_Erase(&FLASH_EraseInitStruct,&error);
}

uint8_t flash_write(volatile uint32_t* address, uint32_t *data, uint16_t size)
{
   for (int i = 0; i < size; i++)
     if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, (*address)+(i*4), data[i]) != HAL_OK)
    	return 1;
   return 0;
}
