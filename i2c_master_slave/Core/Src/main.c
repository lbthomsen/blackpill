/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define I2C_REGISTER_FINGERPRINT 0x00
#define I2C_REGISTER_ID 0x01
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;
I2C_HandleTypeDef hi2c2;

UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */
// emulated I2C RAM
static uint8_t i2c_buffer[256];
static uint16_t i2c_register = 0; 	// current i2c register address
static uint16_t i2c_byte = 0;	// first byte --> new offset
static uint8_t rx_buffer[32], tx_buffer[32];
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
static void MX_I2C2_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

// Send printf to uart1
int _write(int fd, char* ptr, int len) {
  HAL_StatusTypeDef hstatus;

  if (fd == 1 || fd == 2) {
    hstatus = HAL_UART_Transmit(&huart1, (uint8_t *) ptr, len, HAL_MAX_DELAY);
    if (hstatus == HAL_OK)
      return len;
    else
      return -1;
  }
  return -1;
}

void HAL_I2C_ListenCpltCallback(I2C_HandleTypeDef *hi2c)
{
	DBG("ListenCb");
	i2c_byte = 0;
	HAL_I2C_EnableListen_IT(hi2c); // slave is ready again
}

void HAL_I2C_AddrCallback(I2C_HandleTypeDef *hi2c, uint8_t TransferDirection, uint16_t AddrMatchCode)
{
	DBG("AddrCb %s", TransferDirection==I2C_DIRECTION_RECEIVE ? "rx" : "tx" );

	if( TransferDirection==I2C_DIRECTION_TRANSMIT ) {
		if( i2c_byte == 0 ) {
			HAL_I2C_Slave_Seq_Receive_IT(hi2c, &i2c_register, 1, I2C_NEXT_FRAME);
		} else {
			HAL_I2C_Slave_Seq_Receive_IT(hi2c, &rx_buffer, 1, I2C_NEXT_FRAME);
		}
	} else {
		HAL_I2C_Slave_Seq_Transmit_IT(hi2c, &tx_buffer, 1, I2C_NEXT_FRAME);
	}

}

void HAL_I2C_SlaveRxCpltCallback(I2C_HandleTypeDef *hi2c)
{

	if(i2c_offset == 0) {
		DBG("SlaveRxCB: register <== 0x%4x", i2c_register );
		i2c_offset++;
	} else {
		DBG("SlaveRxCB: ram[%3d] <== %3d", i2c_register,  0 );
		i2c_register++;
	}
	HAL_I2C_Slave_Seq_Receive_IT(hi2c, &slave_rx_buffer[0], 1, I2C_NEXT_FRAME);
}

void HAL_I2C_SlaveTxCpltCallback(I2C_HandleTypeDef *hi2c)
{
	DBG("TXCB: ram[%3d] ==> %3d", offset, ram[i2c_offset] );
	i2c_offset++;
	HAL_I2C_Slave_Seq_Transmit_IT(hi2c, &ram[offset], 1, I2C_NEXT_FRAME);
}

void HAL_I2C_ErrorCallback(I2C_HandleTypeDef *hi2c)
{
	if( HAL_I2C_GetError(hi2c)==HAL_I2C_ERROR_AF ) {
		// transaction terminated by master
		DBG("ECB end" );
		offset--;
	} else {
		DBG("ECB err=0x%02lx", HAL_I2C_GetError(hi2c) );
	}
}

void HAL_I2C_AbortCpltCallback(I2C_HandleTypeDef *hi2c)
{
	DBG("aborted" );  // never seen...
}


/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_I2C2_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */

  DBG("\n\n\nStarting up");

  HAL_I2C_EnableListen_IT( &hi2c2 ); // slave is ready

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

	  static uint8_t tx_data[20];
	  static uint8_t rx_data[20];

	  tx_data[0] = 20;
	  tx_data[1] = 10;

	  HAL_I2C_Master_Transmit(&hi2c1, I2C_SLAVE_ADDR << 1, tx_data, 2, HAL_MAX_DELAY);

	  HAL_I2C_Master_Receive(&hi2c1, I2C_SLAVE_ADDR << 1, rx_data, 2, HAL_MAX_DELAY);

	  DBG("HAL_I2C_Mem_Write( &hi2c1, I2C_SLAVE_ADDR << 1, 1, I2C_MEMADD_SIZE_8BIT, \"AB\", 2, HAL_MAX_DELAY );" );
	  HAL_I2C_Mem_Write( &hi2c1, I2C_SLAVE_ADDR << 1, 1, I2C_MEMADD_SIZE_8BIT, "AB", 2, HAL_MAX_DELAY );

	  DBG("HAL_I2C_Mem_Read( &hi2c1, I2C_SLAVE_ADDR << 1, 2, I2C_MEMADD_SIZE_8BIT, rx_data, 1, HAL_MAX_DELAY );");
	  HAL_I2C_Mem_Read( &hi2c1, I2C_SLAVE_ADDR << 1, 2, I2C_MEMADD_SIZE_8BIT, rx_data, 1, HAL_MAX_DELAY );

	  DBG("HAL_I2C_Mem_Write( &hi2c1, I2C_SLAVE_ADDR, 5, I2C_MEMADD_SIZE_8BIT, \"0123456789\", 10, HAL_MAX_DELAY );");
	  HAL_I2C_Mem_Write( &hi2c1, I2C_SLAVE_ADDR << 1, 5, I2C_MEMADD_SIZE_8BIT, "0123456789", 10, HAL_MAX_DELAY );

	  DBG("HAL_I2C_Mem_Read( &hi2c1, I2C_SLAVE_ADDR, 5, I2C_MEMADD_SIZE_8BIT, rx_data, 5, HAL_MAX_DELAY );");
	  HAL_I2C_Mem_Read( &hi2c1, I2C_SLAVE_ADDR << 1, 5, I2C_MEMADD_SIZE_8BIT, rx_data, 5, HAL_MAX_DELAY );

	  DBG("HAL_I2C_Master_Receive( &hi2c1, I2C_SLAVE_ADDR, rx_data, 5, HAL_MAX_DELAY );");
	  HAL_I2C_Master_Receive( &hi2c1, I2C_SLAVE_ADDR << 1, rx_data, 5, HAL_MAX_DELAY );
	  HAL_Delay(10000);


    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 192;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 400000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief I2C2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C2_Init(void)
{

  /* USER CODE BEGIN I2C2_Init 0 */

  /* USER CODE END I2C2_Init 0 */

  /* USER CODE BEGIN I2C2_Init 1 */

  /* USER CODE END I2C2_Init 1 */
  hi2c2.Instance = I2C2;
  hi2c2.Init.ClockSpeed = 400000;
  hi2c2.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c2.Init.OwnAddress1 = 40;
  hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c2.Init.OwnAddress2 = 0;
  hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C2_Init 2 */

  /* USER CODE END I2C2_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 921600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
