/*
 * slavelib.h
 *
 *  Created on: Jun 21, 2023
 *      Author: lth
 */

#ifndef SLAVELIB_H_
#define SLAVELIB_H_

typedef enum {
    SLAVE_REGISTER_RO,
    SLAVE_REGISTER_RQ,
    SLAVE_REGISTER_MEM
} slave_register_type_typedef;

typedef struct {
    uint16_t register_address;
    slave_register_type_typedef register_type;
    const uint8_t *data_address;
} slave_register_typedef;

#endif /* SLAVELIB_H_ */
