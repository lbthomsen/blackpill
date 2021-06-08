/**
  ******************************************************************************
  * @file           : usbd_custom_hid_if.c
  * @brief          : USB Device Custom HID interface file.
  ******************************************************************************
  * COPYRIGHT(c) 2016 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  * 1. Redistributions of source code must retain the above copyright notice,
  * this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  * this list of conditions and the following disclaimer in the documentation
  * and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of its contributors
  * may be used to endorse or promote products derived from this software
  * without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include "usbd_custom_hid_if.h"
/* USER CODE BEGIN INCLUDE */
#include "Handler.h"
/* USER CODE END INCLUDE */
/** @addtogroup STM32_USB_OTG_DEVICE_LIBRARY
  * @{
  */

/** @defgroup USBD_CUSTOM_HID 
  * @brief usbd core module
  * @{
  */ 

/** @defgroup USBD_CUSTOM_HID_Private_TypesDefinitions
  * @{
  */ 
/* USER CODE BEGIN PRIVATE_TYPES */

/* USER CODE END PRIVATE_TYPES */ 
/**
  * @}
  */ 

/** @defgroup USBD_CUSTOM_HID_Private_Defines
  * @{
  */ 
/* USER CODE BEGIN PRIVATE_DEFINES */
/* USER CODE END PRIVATE_DEFINES */
  
/**
  * @}
  */ 

/** @defgroup USBD_CUSTOM_HID_Private_Macros
  * @{
  */ 
/* USER CODE BEGIN PRIVATE_MACRO */
/* USER CODE END PRIVATE_MACRO */

/**
  * @}
  */ 

/** @defgroup USBD_AUDIO_IF_Private_Variables
 * @{
 */
__ALIGN_BEGIN static uint8_t CUSTOM_HID_ReportDesc_FS[USBD_CUSTOM_HID_REPORT_DESC_SIZE] __ALIGN_END =
{
  /* USER CODE BEGIN 0 */ 
	//from PC
  0x06,0x00,0xFF,   //USAGE_PAGE (GENERIC DESCTOP)
    0x09, 0x01,                    // USAGE (Vendor Usage 1)
    0xa1, 0x01,                    // COLLECTION (Application)
    0x85, 0x01,                    //   REPORT_ID (1)
    0x09, 0x01,                    //   USAGE (Vendor Usage 1)
    0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
    0x25, 0xFF,                    //   LOGICAL_MAXIMUM (1)
    0x75, 0x08,                    //   REPORT_SIZE (8)
    0x95, 0x1F,                    //   REPORT_COUNT (32)
    0xB1, 0x82,                    //   FEATURE (Data,Var,Abs,Vol)
    0x85, 0x01,                    //   REPORT_ID (1)
    0x09, 0x01,                    //   USAGE (Vendor Usage 1)
    0x91, 0x82,                    //   OUTPUT (Data,Var,Abs,Vol)
		
		0x85, 0x03,                    //   REPORT_ID (3)
    0x09, 0x03,                    //   USAGE (Vendor Usage 3)
    0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
    0x25, 0xFF,                    //   LOGICAL_MAXIMUM (255)
    0x75, 0x08,                    //   REPORT_SIZE (8)
    0x95, 0x1F,                    //   REPORT_COUNT (32)
    0xB1, 0x82,                    //   FEATURE (Data,Var,Abs,Vol)
    0x85, 0x03,                    //   REPORT_ID (3)
    0x09, 0x03,                    //   USAGE (Vendor Usage 3)
    0x91, 0x82,                    //   OUTPUT (Data,Var,Abs,Vol)
		
		0x85, 0x05,                    //   REPORT_ID (5)
    0x09, 0x05,                    //   USAGE (Vendor Usage 5)
    0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
    0x25, 0xFF,                    //   LOGICAL_MAXIMUM (255)
    0x75, 0x08,                    //   REPORT_SIZE (8)
    0x95, 0x1F,                    //   REPORT_COUNT (32)
    0xB1, 0x82,                    //   FEATURE (Data,Var,Abs,Vol)
    0x85, 0x05,                    //   REPORT_ID (5)
    0x09, 0x05,                    //   USAGE (Vendor Usage 5)
    0x91, 0x82,                    //   OUTPUT (Data,Var,Abs,Vol)
//to PC
		0x85, 0x02,                    //   REPORT_ID (2)
    0x09, 0x02,                    //   USAGE (Vendor Usage 2)
    0x75, 0x08,                    //   REPORT_SIZE (8)
    0x95, 0x1F,                    //   REPORT_COUNT (32)
    0x81, 0x82,										 //		INPUT (Data,Var,Abs,Vol)

    0x85, 0x04,                    //   REPORT_ID (4)
    0x09, 0x04,                    //   USAGE (Vendor Usage 4)
    0x75, 0x08,                    //   REPORT_SIZE (8)
    0x95, 0x1F,                    //   REPORT_COUNT (32)
    0x81, 0x82,										 //		INPUT (Data,Var,Abs,Vol)

    0x85, 0x06,                    //   REPORT_ID (6)
    0x09, 0x06,                    //   USAGE (Vendor Usage 6)
    0x75, 0x08,                    //   REPORT_SIZE (8)
    0x95, 0x1F,                    //   REPORT_COUNT (32) 0x04
    0x81, 0x82,                    //   INPUT (Data,Var,Abs,Vol) 
  /* USER CODE END 0 */ 
  0xC0    /*     END_COLLECTION	             */
   
}; 

/* USER CODE BEGIN PRIVATE_VARIABLES */
extern char uart_tx[BUF_SIZE], spi_tx[BUF_SIZE];
extern uint8_t countTx, writePointerTx, spiCountTx, spiWritePointerTx;

/* USER CODE END PRIVATE_VARIABLES */
/**
  * @}
  */ 
  
/** @defgroup USBD_CUSTOM_HID_IF_Exported_Variables
  * @{
  */ 
  extern USBD_HandleTypeDef hUsbDeviceFS;
/* USER CODE BEGIN EXPORTED_VARIABLES */
extern uint8_t uartBusy;
/* USER CODE END EXPORTED_VARIABLES */

/**
  * @}
  */ 
  
/** @defgroup USBD_CUSTOM_HID_Private_FunctionPrototypes
  * @{
  */
static int8_t CUSTOM_HID_Init_FS     (void);
static int8_t CUSTOM_HID_DeInit_FS   (void);
static int8_t CUSTOM_HID_OutEvent_FS (uint8_t event_idx, uint8_t state);
 

USBD_CUSTOM_HID_ItfTypeDef USBD_CustomHID_fops_FS = 
{
  CUSTOM_HID_ReportDesc_FS,
  CUSTOM_HID_Init_FS,
  CUSTOM_HID_DeInit_FS,
  CUSTOM_HID_OutEvent_FS,
};

/* Private functions ---------------------------------------------------------*/
/**
  * @brief  CUSTOM_HID_Init_FS
  *         Initializes the CUSTOM HID media low layer
  * @param  None
  * @retval Result of the operation: USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CUSTOM_HID_Init_FS(void)
{ 
  /* USER CODE BEGIN 4 */ 
  return (0);
  /* USER CODE END 4 */ 
}

/**
  * @brief  CUSTOM_HID_DeInit_FS
  *         DeInitializes the CUSTOM HID media low layer
  * @param  None
  * @retval Result of the operation: USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CUSTOM_HID_DeInit_FS(void)
{
  /* USER CODE BEGIN 5 */ 
  return (0);
  /* USER CODE END 5 */ 
}

/**
  * @brief  CUSTOM_HID_OutEvent_FS
  *         Manage the CUSTOM HID class events       
  * @param  event_idx: event index
  * @param  state: event state
  * @retval Result of the operation: USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CUSTOM_HID_OutEvent_FS  (uint8_t event_idx, uint8_t state)
{ 
  /* USER CODE BEGIN 6 */ 
	USBD_CUSTOM_HID_HandleTypeDef *hhid = (USBD_CUSTOM_HID_HandleTypeDef*)hUsbDeviceFS.pClassData;
	uint8_t id = hhid->Report_buf[0];
	uint8_t informByte = hhid->Report_buf[1];
	if(id==USB_SETTINGS){
		uint8_t tmp[32] = "\0";
		tmp[0]=USB_ANSWER;
		if(informByte==UART_BUSY_RESET || informByte==UART_BUSY_SET)//0|1
			uartBusy = informByte;
		else if (informByte==CS_SET)//2
			cs_set();
		else if (informByte==CS_RESET)//3
			cs_reset();
		tmp[1]=informByte;
		USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, tmp, 32);
	}else if (id==USB_UART_TX){
		//send received data to uart
		for(uint8_t i=2;i<informByte+2;i++){//informByte contains length
			uart_tx[writePointerTx]=hhid->Report_buf[i];
			writePointerTx=(writePointerTx+1)%BUF_SIZE;
			countTx++;
		}
	}else if (id==USB_SPI_TX){
		//send received data to SPI
		for(uint8_t i=2;i<informByte+2;i++){//informByte contains length
			spi_tx[spiWritePointerTx]=hhid->Report_buf[i];
			spiWritePointerTx=(spiWritePointerTx+1)%BUF_SIZE;
			spiCountTx++;
		}
	}
	
  return (0);
  /* USER CODE END 6 */ 
}

/* USER CODE BEGIN 7 */ 
/**
  * @brief  USBD_CUSTOM_HID_SendReport_FS
  *         Send the report to the Host       
  * @param  report: the report to be sent
  * @param  len: the report length
  * @retval Result of the operation: USBD_OK if all operations are OK else USBD_FAIL
  */
/*  
static int8_t USBD_CUSTOM_HID_SendReport_FS ( uint8_t *report,uint16_t len)
{
  return USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, report, len); 
}
*/
/* USER CODE END 7 */ 

/* USER CODE BEGIN PRIVATE_FUNCTIONS_IMPLEMENTATION */
/* USER CODE END PRIVATE_FUNCTIONS_IMPLEMENTATION */

/**
  * @}
  */ 

/**
  * @}
  */  
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
