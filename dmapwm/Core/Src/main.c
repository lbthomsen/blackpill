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
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define BUFFER_SIZE 10
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim10;
DMA_HandleTypeDef hdma_tim3_ch1_trig;
DMA_HandleTypeDef hdma_tim3_ch2;

UART_HandleTypeDef huart1;

/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = { .name = "defaultTask",
		.stack_size = 128 * 4, .priority = (osPriority_t) osPriorityNormal, };
/* Definitions for ledTask */
osThreadId_t ledTaskHandle;
const osThreadAttr_t ledTask_attributes = { .name = "ledTask", .stack_size = 128
		* 4, .priority = (osPriority_t) osPriorityLow, };
/* Definitions for pwmBuf1Task */
osThreadId_t pwmBuf1TaskHandle;
const osThreadAttr_t pwmBuf1Task_attributes = { .name = "pwmBuf1Task",
		.stack_size = 128 * 4, .priority = (osPriority_t) osPriorityLow, };
/* Definitions for pwmBuf2Task */
osThreadId_t pwmBuf2TaskHandle;
const osThreadAttr_t pwmBuf2Task_attributes = { .name = "pwmBuf2Task",
		.stack_size = 128 * 4, .priority = (osPriority_t) osPriorityLow, };
/* Definitions for statusTask */
osThreadId_t statusTaskHandle;
const osThreadAttr_t statusTask_attributes = { .name = "statusTask",
		.stack_size = 256 * 4, .priority = (osPriority_t) osPriorityLow, };
/* Definitions for pwm1Queue */
osMessageQueueId_t pwm1QueueHandle;
const osMessageQueueAttr_t pwm1Queue_attributes = { .name = "pwm1Queue" };
/* Definitions for pwm2Queue */
osMessageQueueId_t pwm2QueueHandle;
const osMessageQueueAttr_t pwm2Queue_attributes = { .name = "pwm2Queue" };
/* USER CODE BEGIN PV */

volatile unsigned long ulHighFrequencyTimerTicks;

uint16_t dma_buffer1[BUFFER_SIZE * 2] = { 0 };
uint16_t dma_buffer2[BUFFER_SIZE * 2] = { 0 };
uint16_t pwm_value = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_TIM3_Init(void);
static void MX_TIM10_Init(void);
void startDefaultTask(void *argument);
void startLedTask(void *argument);
void startPwmBuf1Task(void *argument);
void startPwmBuf2Task(void *argument);
void startStatusTask(void *argument);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

// Send printf to uart1
int _write(int fd, char *ptr, int len) {
	HAL_StatusTypeDef hstatus;

	if (fd == 1 || fd == 2) {
		hstatus = HAL_UART_Transmit(&huart1, (uint8_t*) ptr, len,
				HAL_MAX_DELAY);
		if (hstatus == HAL_OK)
			return len;
		else
			return -1;
	}
	return -1;
}

// Done sending first half of the DMA buffer - this can now safely be updated
void HAL_TIM_PWM_PulseFinishedHalfCpltCallback(TIM_HandleTypeDef *htim) {

	BaseType_t xHigherPriorityTaskWoken = pdFALSE;

	if (htim->Instance == TIM3) {
		if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1) {
			xTaskGenericNotifyFromISR(pwmBuf1TaskHandle,
					(uint32_t) &dma_buffer1[0], eSetValueWithOverwrite, NULL,
					xHigherPriorityTaskWoken);
		} else {
			xTaskGenericNotifyFromISR(pwmBuf2TaskHandle,
					(uint32_t) &dma_buffer2[0], eSetValueWithOverwrite, NULL,
					xHigherPriorityTaskWoken);
		}
		//update_next_buffer(&dma_buffer[BUFFER_SIZE]);
	}

}

// Done sending the second half of the DMA buffer - this can now be safely updated
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim) {

	BaseType_t xHigherPriorityTaskWoken = pdFALSE;

	if (htim->Instance == TIM3) {
		if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1) {
			xTaskGenericNotifyFromISR(pwmBuf1TaskHandle,
					(uint32_t) &dma_buffer1[BUFFER_SIZE],
					eSetValueWithOverwrite, NULL, xHigherPriorityTaskWoken);
		} else {
			xTaskGenericNotifyFromISR(pwmBuf2TaskHandle,
					(uint32_t) &dma_buffer2[BUFFER_SIZE],
					eSetValueWithOverwrite, NULL, xHigherPriorityTaskWoken);
		}
		//update_next_buffer(&dma_buffer[BUFFER_SIZE]);
	}

}

void configureTimerForRunTimeStats(void) {
	ulHighFrequencyTimerTicks = 0;
	HAL_TIM_Base_Start_IT(&htim10);
}

unsigned long getRunTimeCounterValue(void) {
	return ulHighFrequencyTimerTicks;
}

/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void) {
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
	MX_DMA_Init();
	MX_USART1_UART_Init();
	MX_TIM3_Init();
	MX_TIM10_Init();
	/* USER CODE BEGIN 2 */

	HAL_Delay(3000);

	DBG("\n\n\nFiring up!");

	/* USER CODE END 2 */

	/* Init scheduler */
	osKernelInitialize();

	/* USER CODE BEGIN RTOS_MUTEX */
	/* add mutexes, ... */
	/* USER CODE END RTOS_MUTEX */

	/* USER CODE BEGIN RTOS_SEMAPHORES */
	/* add semaphores, ... */
	/* USER CODE END RTOS_SEMAPHORES */

	/* USER CODE BEGIN RTOS_TIMERS */
	/* start timers, add new ones, ... */
	/* USER CODE END RTOS_TIMERS */

	/* Create the queue(s) */
	/* creation of pwm1Queue */
	pwm1QueueHandle = osMessageQueueNew(16, sizeof(uint32_t),
			&pwm1Queue_attributes);

	/* creation of pwm2Queue */
	pwm2QueueHandle = osMessageQueueNew(16, sizeof(uint32_t),
			&pwm2Queue_attributes);

	/* USER CODE BEGIN RTOS_QUEUES */
	/* add queues, ... */
	/* USER CODE END RTOS_QUEUES */

	/* Create the thread(s) */
	/* creation of defaultTask */
	defaultTaskHandle = osThreadNew(startDefaultTask, NULL,
			&defaultTask_attributes);

	/* creation of ledTask */
	ledTaskHandle = osThreadNew(startLedTask, NULL, &ledTask_attributes);

	/* creation of pwmBuf1Task */
	pwmBuf1TaskHandle = osThreadNew(startPwmBuf1Task, NULL,
			&pwmBuf1Task_attributes);

	/* creation of pwmBuf2Task */
	pwmBuf2TaskHandle = osThreadNew(startPwmBuf2Task, NULL,
			&pwmBuf2Task_attributes);

	/* creation of statusTask */
	statusTaskHandle = osThreadNew(startStatusTask, NULL,
			&statusTask_attributes);

	/* USER CODE BEGIN RTOS_THREADS */
	/* add threads, ... */
	/* USER CODE END RTOS_THREADS */

	/* USER CODE BEGIN RTOS_EVENTS */
	/* add events, ... */
	/* USER CODE END RTOS_EVENTS */

	/* Start scheduler */
	osKernelStart();

	/* We should never get here as control is now taken by the scheduler */
	/* Infinite loop */
	/* USER CODE BEGIN WHILE */

	uint32_t now, last_tick = 0, last_blink = 0;

	while (1) {

		now = HAL_GetTick();

		if (now - last_blink >= 500) {
			HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
			last_blink = now;
		}

		if (now - last_tick >= 1000) {
			DBG("Tick %lu", now / 1000);
			last_tick = now;
		}

		/* USER CODE END WHILE */

		/* USER CODE BEGIN 3 */
	}
	/* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void) {
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

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
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}
	/** Initializes the CPU, AHB and APB buses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK) {
		Error_Handler();
	}
}

/**
 * @brief TIM3 Initialization Function
 * @param None
 * @retval None
 */
static void MX_TIM3_Init(void) {

	/* USER CODE BEGIN TIM3_Init 0 */

	/* USER CODE END TIM3_Init 0 */

	TIM_ClockConfigTypeDef sClockSourceConfig = { 0 };
	TIM_MasterConfigTypeDef sMasterConfig = { 0 };
	TIM_OC_InitTypeDef sConfigOC = { 0 };

	/* USER CODE BEGIN TIM3_Init 1 */

	/* USER CODE END TIM3_Init 1 */
	htim3.Instance = TIM3;
	htim3.Init.Prescaler = 95;
	htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim3.Init.Period = PWM_CNT;
	htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim3) != HAL_OK) {
		Error_Handler();
	}
	sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK) {
		Error_Handler();
	}
	if (HAL_TIM_PWM_Init(&htim3) != HAL_OK) {
		Error_Handler();
	}
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig)
			!= HAL_OK) {
		Error_Handler();
	}
	sConfigOC.OCMode = TIM_OCMODE_PWM1;
	sConfigOC.Pulse = 0;
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_1)
			!= HAL_OK) {
		Error_Handler();
	}
	if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_2)
			!= HAL_OK) {
		Error_Handler();
	}
	/* USER CODE BEGIN TIM3_Init 2 */

	/* USER CODE END TIM3_Init 2 */
	HAL_TIM_MspPostInit(&htim3);

}

/**
 * @brief TIM10 Initialization Function
 * @param None
 * @retval None
 */
static void MX_TIM10_Init(void) {

	/* USER CODE BEGIN TIM10_Init 0 */

	/* USER CODE END TIM10_Init 0 */

	/* USER CODE BEGIN TIM10_Init 1 */

	/* USER CODE END TIM10_Init 1 */
	htim10.Instance = TIM10;
	htim10.Init.Prescaler = 0;
	htim10.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim10.Init.Period = 959;
	htim10.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim10.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim10) != HAL_OK) {
		Error_Handler();
	}
	/* USER CODE BEGIN TIM10_Init 2 */

	/* USER CODE END TIM10_Init 2 */

}

/**
 * @brief USART1 Initialization Function
 * @param None
 * @retval None
 */
static void MX_USART1_UART_Init(void) {

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
	if (HAL_UART_Init(&huart1) != HAL_OK) {
		Error_Handler();
	}
	/* USER CODE BEGIN USART1_Init 2 */

	/* USER CODE END USART1_Init 2 */

}

/**
 * Enable DMA controller clock
 */
static void MX_DMA_Init(void) {

	/* DMA controller clock enable */
	__HAL_RCC_DMA1_CLK_ENABLE();

	/* DMA interrupt init */
	/* DMA1_Stream4_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(DMA1_Stream4_IRQn, 5, 0);
	HAL_NVIC_EnableIRQ(DMA1_Stream4_IRQn);
	/* DMA1_Stream5_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(DMA1_Stream5_IRQn, 5, 0);
	HAL_NVIC_EnableIRQ(DMA1_Stream5_IRQn);

}

/**
 * @brief GPIO Initialization Function
 * @param None
 * @retval None
 */
static void MX_GPIO_Init(void) {
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOH_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pin : LED_Pin */
	GPIO_InitStruct.Pin = LED_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(LED_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/* USER CODE BEGIN Header_startDefaultTask */
/**
 * @brief  Function implementing the defaultTask thread.
 * @param  argument: Not used
 * @retval None
 */
/* USER CODE END Header_startDefaultTask */
void startDefaultTask(void *argument) {
	/* USER CODE BEGIN 5 */
	/* Infinite loop */
	for (;;) {
		osDelay(1000);
		DBG("Tick %lu", osKernelGetTickCount() / 1000);
	}
	/* USER CODE END 5 */
}

/* USER CODE BEGIN Header_startLedTask */
/**
 * @brief Function implementing the ledTask thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_startLedTask */
void startLedTask(void *argument) {
	/* USER CODE BEGIN startLedTask */

	uint32_t oldValue;

	/* Infinite loop */
	for (;;) {
		osDelay(500);
		HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
	}
	/* USER CODE END startLedTask */
}

/* USER CODE BEGIN Header_startPwmBuf1Task */
/**
 * @brief Function implementing the pwmBuf1Task thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_startPwmBuf1Task */
void startPwmBuf1Task(void *argument) {
	/* USER CODE BEGIN startPwmBuf1Task */

	HAL_TIM_PWM_Start_DMA(&htim3, TIM_CHANNEL_1, (uint32_t*) &dma_buffer1,
			BUFFER_SIZE * 2);

	int32_t counter_change = 1;
	int32_t counter = 10;
	uint32_t notificationValue;
	uint16_t *buffer_pointer;

	/* Infinite loop */
	for (;;) {

		xTaskNotifyWait(0, 0, &notificationValue, osWaitForever);
		//DBG("1 Got %x", notificationValue);

		buffer_pointer = (uint16_t*) notificationValue;
		for (int i = 0; i < BUFFER_SIZE; i++) {
			*buffer_pointer = counter;
			buffer_pointer++;
		}

		counter += counter_change;
		if (counter <= 10) {
			counter_change = 1;
		}
		if (counter >= PWM_CNT - 10) {
			counter_change = -1;
		}

	}
	/* USER CODE END startPwmBuf1Task */
}

/* USER CODE BEGIN Header_startPwmBuf2Task */
/**
 * @brief Function implementing the pwmBuf2Task thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_startPwmBuf2Task */
void startPwmBuf2Task(void *argument) {
	/* USER CODE BEGIN startPwmBuf2Task */

	HAL_TIM_PWM_Start_DMA(&htim3, TIM_CHANNEL_2, (uint32_t*) &dma_buffer2,
			BUFFER_SIZE * 2);

	int32_t counter = 10;
	int32_t counter_change = 1;
	uint32_t notificationValue;
	uint16_t *buffer_pointer;

	/* Infinite loop */
	for (;;) {
		xTaskNotifyWait(0, 0, &notificationValue, osWaitForever);
		//DBG("2 Got %x", notificationValue);

		buffer_pointer = (uint16_t*) notificationValue;
		for (int i = 0; i < BUFFER_SIZE; i++) {
			*buffer_pointer = counter;
			buffer_pointer++;

			counter += counter_change;
			if (counter <= 10) {
				counter_change = 1;
			}
			if (counter >= PWM_CNT - 10) {
				counter_change = -1;
			}
		}

	}
	/* USER CODE END startPwmBuf2Task */
}

/* USER CODE BEGIN Header_startStatusTask */
/**
 * @brief Function implementing the statusTask thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_startStatusTask */
void startStatusTask(void *argument) {
	/* USER CODE BEGIN startStatusTask */

	TaskStatus_t *pxTaskStatusArray;
	volatile UBaseType_t uxArraySize, x;
	unsigned long ulTotalRunTime;
	float runtime_percent;

	/* Infinite loop */
	for (;;) {
		osDelay(10000);

		uxArraySize = uxTaskGetNumberOfTasks();
		pxTaskStatusArray = pvPortMalloc(uxArraySize * sizeof(TaskStatus_t)); // a little bit scary!

		if (pxTaskStatusArray != NULL) {
			uxArraySize = uxTaskGetSystemState(pxTaskStatusArray, uxArraySize,
					&ulTotalRunTime);

			DBG("Task count = %lu", uxArraySize);
			DBG("No      Name          S Usage   HW");

			for (x = 0; x < uxArraySize; x++) {

				runtime_percent = (float) (100
						* (float) pxTaskStatusArray[x].ulRunTimeCounter
						/ (float) ulTotalRunTime);

				DBG("Task %lu: %-12s %2d %7.4f %4i", x,
						pxTaskStatusArray[x].pcTaskName,
						pxTaskStatusArray[x].eCurrentState, runtime_percent,
						pxTaskStatusArray[x].usStackHighWaterMark);

			}

			vPortFree(pxTaskStatusArray);

		} else {
			DBG("Unable to allocate stack space");
		}

	}

	/* USER CODE END startStatusTask */
}

/**
 * @brief  Period elapsed callback in non blocking mode
 * @note   This function is called  when TIM11 interrupt took place, inside
 * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
 * a global variable "uwTick" used as application time base.
 * @param  htim : TIM handle
 * @retval None
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	/* USER CODE BEGIN Callback 0 */

	/* USER CODE END Callback 0 */
	if (htim->Instance == TIM11) {
		HAL_IncTick();
	}
	/* USER CODE BEGIN Callback 1 */

	/* USER CODE END Callback 1 */
}

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void) {
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1) {
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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
