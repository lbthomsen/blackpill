/*
 * slavelib.h
 *
 *  Created on: Jun 21, 2023
 *      Author: lth
 */

#ifndef SLAVELIB_H_
#define SLAVELIB_H_

#ifdef DEBUG
#define SLAVE_DBG DBG
#endif

typedef enum {
    SLAVE_Ok,
    SLAVE_Err
} slave_return_type;

typedef enum {
    SLAVE_REGISTER_RO,
    SLAVE_REGISTER_RQ,
    SLAVE_REGISTER_MEM
} slave_register_type_typedef;

typedef struct {
    const uint16_t register_address;
    const slave_register_type_typedef register_type;
    const uint8_t *data_address;
    const uint16_t data_len;
} slave_register_typedef;

#ifdef HAL_I2C_MODULE_ENABLED

typedef struct {
    I2C_HandleTypeDef *i2c_handle;
    uint8_t receive_count;
    uint8_t receive_buffer[32];
} slave_i2c_handle_typedef;

slave_return_type slave_i2c_init(slave_i2c_handle_typedef *i2c_slave, I2C_HandleTypeDef *i2c_handle);

void slave_i2c_tx_callback(slave_i2c_handle_typedef *i2c_slave);
void slave_i2c_rx_callback(slave_i2c_handle_typedef *i2c_slave);
void slave_i2c_addr_callback(slave_i2c_handle_typedef *i2c_slave, uint8_t direction, uint16_t match_code);
void slave_i2c_listen_callback(slave_i2c_handle_typedef *i2c_slave);
void slave_i2c_mem_tx_callback(slave_i2c_handle_typedef *i2c_slave);
void slave_i2c_mem_rx_callback(slave_i2c_handle_typedef *i2c_slave);
void slave_i2c_error_callback(slave_i2c_handle_typedef *i2c_slave);
void slave_i2c_abort_callback(slave_i2c_handle_typedef *i2c_slave);

#endif

#ifdef HAL_SPI_MODULE_ENABLED

typedef struct {
    SPI_HandleTypeDef *spi_handle;
} slave_spi_handle_typedef;

slave_return_type slave_spi_init();

#endif

#endif /* SLAVELIB_H_ */
