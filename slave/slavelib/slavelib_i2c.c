/*
 * slavelib_i2c.c
 *
 *  Created on: Jun 24, 2023
 *      Author: lth
 */

#include "main.h"
#include "slavelib.h"

slave_return_type slave_i2c_init(slave_i2c_handle_typedef *i2c_slave, I2C_HandleTypeDef *i2c_handle) {

    SLAVE_DBG("Initializing i2c slave");

    i2c_slave->i2c_handle = i2c_handle;

    if(HAL_I2C_EnableListen_IT(i2c_slave->i2c_handle) != HAL_OK) {
        return SLAVE_Err;
    }

    return SLAVE_Ok;

}

void slave_i2c_tx_callback(slave_i2c_handle_typedef *i2c_slave) {
    SLAVE_DBG("slave_i2c_tx_callback");
}

void slave_i2c_rx_callback(slave_i2c_handle_typedef *i2c_slave) {
    SLAVE_DBG("slave_i2c_rx_callback");
}

void slave_i2c_addr_callback(slave_i2c_handle_typedef *i2c_slave, uint8_t direction, uint16_t match_code) {
    SLAVE_DBG("slave_i2c_addr_callback - direction = %d addr = 0x%04x", direction, match_code);

}

void slave_i2c_listen_callback(slave_i2c_handle_typedef *i2c_slave) {
    SLAVE_DBG("slave_i2c_listen_callback");
}

void slave_i2c_mem_tx_callback(slave_i2c_handle_typedef *i2c_slave) {
    SLAVE_DBG("slave_i2c_mem_tx_callback");
}

void slave_i2c_mem_rx_callback(slave_i2c_handle_typedef *i2c_slave) {
    SLAVE_DBG("slave_i2c_mem_rx_callback");
}
