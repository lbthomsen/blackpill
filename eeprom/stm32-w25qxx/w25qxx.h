/*
 * w25qxx.h
 *
 *  Created on: Jun 2, 2021
 *      Author: lth
 */

#ifndef W25QXX_H_
#define W25QXX_H_

#define W25QXX_DUMMY_BYTE         0xA5
#define W25QXX_GET_ID             0x9F

typedef enum {
        W25QXX_Err,
        W25QXX_Ok
} W25QXX_result_t;

W25QXX_result_t w25qxx_init(SPI_HandleTypeDef *init_hspi, GPIO_TypeDef *init_gpio_port, uint16_t init_gpio_pin);

#endif /* W25QXX_H_ */
