/*
 * slavelib_i2c.c
 *
 *  Created on: Jun 24, 2023
 *      Author: lth
 */

#include "main.h"
#include "slavelib.h"

slave_return_type slave_enable_listen(slave_i2c_handle_typedef *i2c_slave) {

    SLAVE_DBG("Enabling listen");

    if(HAL_I2C_EnableListen_IT(i2c_slave->i2c_handle) != HAL_OK) {
        return SLAVE_Err;
    }

    return SLAVE_Ok;

}

slave_return_type slave_i2c_init(slave_i2c_handle_typedef *i2c_slave, I2C_HandleTypeDef *i2c_handle) {

    SLAVE_DBG("Initializing i2c slave");

    i2c_slave->i2c_handle = i2c_handle;
    i2c_slave->receive_count = 0;

    if (slave_enable_listen(i2c_slave) != SLAVE_Ok) return SLAVE_Err;

    return SLAVE_Ok;

}

void slave_i2c_tx_callback(slave_i2c_handle_typedef *i2c_slave) {
    SLAVE_DBG("slave_i2c_tx_callback");

    slave_enable_listen(i2c_slave);
}

void slave_i2c_rx_callback(slave_i2c_handle_typedef *i2c_slave) {
    SLAVE_DBG("slave_i2c_rx_callback");

    i2c_slave->receive_count++;

    //if (rxcount >= RxSIZE) rxcount = 0;
    HAL_I2C_Slave_Seq_Receive_IT(i2c_slave->i2c_handle, i2c_slave->receive_buffer[i2c_slave->receive_count], 1, I2C_NEXT_FRAME);

    printf("RX count = %d - ", i2c_slave->receive_count);
    for (int i = 0; i < i2c_slave->receive_count; ++i) printf("0x%02x ", i2c_slave->receive_buffer[i]);
    printf("\n");

    i2c_slave->receive_count++;

}

void slave_i2c_addr_callback(slave_i2c_handle_typedef *i2c_slave, uint8_t direction, uint16_t match_code) {
    SLAVE_DBG("slave_i2c_addr_callback - direction = %d addr = 0x%04x", direction, match_code);

    if (direction == I2C_DIRECTION_TRANSMIT) {
        // Transmit
        i2c_slave->receive_count = 1;
        if (HAL_I2C_Slave_Sequential_Receive_IT(i2c_slave->i2c_handle, i2c_slave->receive_buffer, 1, I2C_FIRST_AND_NEXT_FRAME) != HAL_OK) {
            SLAVE_DBG("Some error");
            Error_Handler();
        }
    } else {
        // Receive

    }

}

void slave_i2c_listen_callback(slave_i2c_handle_typedef *i2c_slave) {
    SLAVE_DBG("slave_i2c_listen_callback");
    slave_enable_listen(i2c_slave);
}

void slave_i2c_mem_tx_callback(slave_i2c_handle_typedef *i2c_slave) {
    SLAVE_DBG("slave_i2c_mem_tx_callback");
}

void slave_i2c_mem_rx_callback(slave_i2c_handle_typedef *i2c_slave) {
    SLAVE_DBG("slave_i2c_mem_rx_callback");
}

void slave_i2c_error_callback(slave_i2c_handle_typedef *i2c_slave) {
    SLAVE_DBG("slave_i2c_error_callback");
}

void slave_i2c_abort_callback(slave_i2c_handle_typedef *i2c_slave) {
    SLAVE_DBG("slave_i2c_abort_callback");
}
