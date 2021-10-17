/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * SPI Master and Slave
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "spi.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

#define SLAVE_INSTRUCTION_WAIT 0x00
#define SLAVE_INSTRUCTION_FINGERPRINT 0x01
#define SLAVE_INSTRUCTION_RECEIVING 0xff

#define SLAVE_FINGERPRINT 0xdeadbeef

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

uint8_t slave_tx_buffer[32];
uint8_t slave_receive_byte;

uint8_t master_tx_buffer[32];
uint8_t master_rx_buffer[32];

uint8_t slave_instruction = 0;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
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

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {

	if (GPIO_Pin == BTN_Pin) {
		if (HAL_GPIO_ReadPin(BTN_GPIO_Port, BTN_Pin) == GPIO_PIN_SET) {
			DBG("BTN Release");
		} else {
			DBG("BTN Push");
		}
	} else if (GPIO_Pin == SPI2_SS_Pin) {
		if (HAL_GPIO_ReadPin(SPI2_SS_GPIO_Port, SPI2_SS_Pin) == GPIO_PIN_RESET) {
			DBG("SPI2 SS Selected");
			HAL_SPI_Receive_IT(&hspi2, &slave_receive_byte, 1);
		} else {
			DBG("SPI2 SS Done");
			HAL_SPI_Abort(&hspi2);
			slave_instruction = SLAVE_INSTRUCTION_WAIT;
		}
	}

}

void HAL_SPI_RxCpltCallback(SPI_HandleTypeDef *hspi) {
	DBG("RXCB - received 0x%02x", slave_receive_byte);

	switch (slave_instruction) {

	case SLAVE_INSTRUCTION_WAIT:
		slave_instruction = slave_receive_byte;
		HAL_SPI_Receive_IT(&hspi2, &slave_receive_byte, 1);
		break;

	case SLAVE_INSTRUCTION_FINGERPRINT:
		slave_instruction = SLAVE_INSTRUCTION_RECEIVING;
		slave_tx_buffer[0] = (SLAVE_FINGERPRINT & 0xff000000) >> 24;
		slave_tx_buffer[1] = (SLAVE_FINGERPRINT & 0x00ff0000) >> 16;
		slave_tx_buffer[2] = (SLAVE_FINGERPRINT & 0x0000ff00) >> 8;
		slave_tx_buffer[3] = (SLAVE_FINGERPRINT & 0x000000ff);
		HAL_SPI_Transmit_IT(&hspi2, &slave_tx_buffer[0], 5);
		break;

	case SLAVE_INSTRUCTION_RECEIVING:
		break;
//	default:
//		DBG("Unknown SPI instruction 0x%02x", slave_receive_byte);
//		slave_instruction = SLAVE_INSTRUCTION_WAIT;
//		HAL_SPI_Receive_IT(&hspi2, &slave_receive_byte, 1);
	}


}

void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi) {
	DBG("TXCB");

	HAL_SPI_Receive_IT(&hspi2, &slave_receive_byte, 1);
}

void HAL_SPI_TxRxCpltCallback(SPI_HandleTypeDef *hspi) {
	DBG("TXRXCB");
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
  MX_SPI1_Init();
  MX_SPI2_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  uint32_t now = 0, last_tick = 0, last_blink = 0, last_spi = 0;;

  while (1)
  {

	  now = HAL_GetTick();

	  if (now - last_blink >= 500) {
		  HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
		  last_blink = now;
	  }

	  if (now - last_tick >= 1000) {
		  DBG("Tick %lu", now / 1000);
		  last_tick = now;
	  }

	  if (now - last_spi >= 2000) {

		  DBG("Checking slave fingerprint");
		  //memcpy(&master_tx_buffer[0], 0, sizeof(master_tx_buffer));
		  master_tx_buffer[0] = SLAVE_INSTRUCTION_FINGERPRINT;
		  HAL_GPIO_WritePin(SPI1_SS_GPIO_Port, SPI1_SS_Pin, GPIO_PIN_RESET);
		  HAL_SPI_Transmit(&hspi1, &master_tx_buffer[0], 1, HAL_MAX_DELAY);
		  HAL_SPI_Receive(&hspi1, &master_rx_buffer[0], 5, HAL_MAX_DELAY);
		  //HAL_SPI_TransmitReceive(&hspi1, &master_tx_buffer[0], &master_rx_buffer[0], 5, HAL_MAX_DELAY);
		  HAL_GPIO_WritePin(SPI1_SS_GPIO_Port, SPI1_SS_Pin, GPIO_PIN_SET);

		  DBG("Got 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x", master_rx_buffer[0], master_rx_buffer[1], master_rx_buffer[2], master_rx_buffer[3], master_rx_buffer[4]);

		  last_spi = now;
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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
