/*
 * w25qxx.c
 *
 *  Created on: Jun 2, 2021
 *      Author: lth
 */

#include "main.h"
#include "w25qxx.h"

#ifdef DEBUG
#include "usbd_conf.h"
#define LOG(...)    printf(__VA_ARGS__);\
                    printf("\n");
#endif

SPI_HandleTypeDef *hspi;
GPIO_TypeDef *gpio_port;
uint16_t gpio_pin;

static inline void cs_on() {
	HAL_GPIO_WritePin(gpio_port, gpio_pin, GPIO_PIN_RESET);
}

static inline void cs_off() {
	HAL_GPIO_WritePin(gpio_port, gpio_pin, GPIO_PIN_SET);
}

uint8_t W25QXX_SPI(uint8_t data) {
	uint8_t	ret;
	if (HAL_SPI_TransmitReceive(hspi, &data, &ret, 1, 100) != HAL_OK) {
		Error_Handler();
	}
	return ret;
}

uint32_t W25QXX_read_id(void)
{
  uint32_t d0 = 0, d1 = 0, d2 = 0;
  cs_on();
  W25QXX_SPI(W25QXX_GET_ID);
  d0 = W25QXX_SPI(W25QXX_DUMMY_BYTE);
  d1 = W25QXX_SPI(W25QXX_DUMMY_BYTE);
  d2 = W25QXX_SPI(W25QXX_DUMMY_BYTE);
  cs_off();
  return (d0 << 16) | (d1 << 8) | (d2);
}

W25QXX_result_t w25qxx_init(SPI_HandleTypeDef *init_hspi, GPIO_TypeDef *init_gpio_port, uint16_t init_gpio_pin) {


	printf("w25qxx_init\n");

	hspi = init_hspi;
	gpio_port = init_gpio_port;
	gpio_pin = init_gpio_pin;

	uint32_t id = W25QXX_read_id();

	return W25QXX_Ok;

}
