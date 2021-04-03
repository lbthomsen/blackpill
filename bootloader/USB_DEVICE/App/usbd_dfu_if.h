/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : usbd_dfu_if.h
  * @brief          : Header for usbd_dfu_if.c file.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USBD_DFU_IF_H__
#define __USBD_DFU_IF_H__

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "usbd_dfu.h"

/* USER CODE BEGIN INCLUDE */

/* USER CODE END INCLUDE */

/** @addtogroup STM32_USB_DEVICE_LIBRARY
  * @brief For Usb device.
  * @{
  */

/** @defgroup USBD_MEDIA USBD_MEDIA
  * @brief Header file for the usbd_dfu_if.c file.
  * @{
  */

/** @defgroup USBD_MEDIA_Exported_Defines USBD_MEDIA_Exported_Defines
  * @brief Defines.
  * @{
  */

/* USER CODE BEGIN EXPORTED_DEFINES */
 // 02*016Ka,02*016Kg,01*064Kg,07*128Kg,04*016Kg,01*064Kg,07*128Kg
 #define ADDR_FLASH_SECTOR_0     ((uint32_t)0x08000000) /* Base @ of Sector 0, 32 Kbytes */
 #define ADDR_FLASH_SECTOR_1     ((uint32_t)0x08008000) /* Base @ of Sector 1, 32 Kbytes */
 #define ADDR_FLASH_SECTOR_2     ((uint32_t)0x08010000) /* Base @ of Sector 2, 32 Kbytes */
 #define ADDR_FLASH_SECTOR_3     ((uint32_t)0x08018000) /* Base @ of Sector 3, 32 Kbytes */
 #define ADDR_FLASH_SECTOR_4     ((uint32_t)0x08020000) /* Base @ of Sector 4, 32 Kbytes */
 #define ADDR_FLASH_SECTOR_5     ((uint32_t)0x08028000) /* Base @ of Sector 5, 32 Kbytes */
 #define ADDR_FLASH_SECTOR_6     ((uint32_t)0x08030000) /* Base @ of Sector 6, 32 Kbytes */
 #define ADDR_FLASH_SECTOR_7     ((uint32_t)0x08038000) /* Base @ of Sector 7, 32 Kbytes */
 #define ADDR_FLASH_SECTOR_8     ((uint32_t)0x08040000) /* Base @ of Sector 8, 32 Kbytes */
 #define ADDR_FLASH_SECTOR_9     ((uint32_t)0x08048000) /* Base @ of Sector 9, 32 Kbytes */
 #define ADDR_FLASH_SECTOR_10    ((uint32_t)0x08050000) /* Base @ of Sector 10, 32 Kbytes */
 #define ADDR_FLASH_SECTOR_11    ((uint32_t)0x08058000) /* Base @ of Sector 11, 32 Kbytes */
 #define ADDR_FLASH_SECTOR_12    ((uint32_t)0x08060000) /* Base @ of Sector 12, 32 Kbytes */
 #define ADDR_FLASH_SECTOR_13    ((uint32_t)0x08068000) /* Base @ of Sector 13, 32 Kbytes */
 #define ADDR_FLASH_SECTOR_14    ((uint32_t)0x08070000) /* Base @ of Sector 14, 32 Kbytes */
 #define ADDR_FLASH_SECTOR_15    ((uint32_t)0x08078000) /* Base @ of Sector 15, 32 Kbytes */
/* USER CODE END EXPORTED_DEFINES */

/**
  * @}
  */

/** @defgroup USBD_MEDIA_Exported_Types USBD_MEDIA_Exported_Types
  * @brief Types.
  * @{
  */

/* USER CODE BEGIN EXPORTED_TYPES */

/* USER CODE END EXPORTED_TYPES */

/**
  * @}
  */

/** @defgroup USBD_MEDIA_Exported_Macros USBD_MEDIA_Exported_Macros
  * @brief Aliases.
  * @{
  */

/* USER CODE BEGIN EXPORTED_MACRO */

/* USER CODE END EXPORTED_MACRO */

/**
  * @}
  */

/** @defgroup USBD_MEDIA_Exported_Variables USBD_MEDIA_Exported_Variables
  * @brief Public variables.
  * @{
  */

/** MEDIA Interface callback. */
extern USBD_DFU_MediaTypeDef USBD_DFU_fops_FS;

/* USER CODE BEGIN EXPORTED_VARIABLES */

/* USER CODE END EXPORTED_VARIABLES */

/**
  * @}
  */

/** @defgroup USBD_MEDIA_Exported_FunctionsPrototype USBD_MEDIA_Exported_FunctionsPrototype
  * @brief Public functions declaration.
  * @{
  */

/* USER CODE BEGIN EXPORTED_FUNCTIONS */

/* USER CODE END EXPORTED_FUNCTIONS */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __USBD_DFU_IF_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
