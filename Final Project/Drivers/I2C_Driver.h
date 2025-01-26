
#ifndef DRIVERS_I2C_DRIVER_H_
#define DRIVERS_I2C_DRIVER_H_

#include "global.h"
#define I2C I2C1_BASE
#define I2C_SENSOR_ADDRESS 0x68

#define I2C_REGISTER_ADDRESS 0x41


void i2c_config(void);
void i2c_clock_config(void);
float i2c_read_temperature(void);
uint8_t  i2c_read_register(uint8_t add, uint8_t regist, uint8_t *data);







#endif /* DRIVERS_I2C_DRIVER_H_ */
