/*
 * i2c_driver.h
 *
 *  Created on: Jan 17, 2025
 *      Author: jagoum
 */

#ifndef DRIVERS_I2C_DRIVER_H_
#define DRIVERS_I2C_DRIVER_H_

// Define the I2C clock speed
#define I2C_CLOCK_SPEED 9600


// Define the WSEN-TIDS temperature sensor address
#define WSEN_TIDS_ADDRESS 0x38

// Define the temperature register address
#define TEMPERATURE_REGISTER 0x00


void i2c_setting(void);
void i2c_temperature(void);

#endif /* DRIVERS_I2C_DRIVER_H_ */
