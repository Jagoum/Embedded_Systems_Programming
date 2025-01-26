/*
 * i2c_driver.c
 *
 *  Created on: Jan 17, 2025
 *      Author: jagoum
 */
#include "global.h"
#include "i2c_driver.h"




void i2c_setting(void)
{
    // Initialize the GPIO pins for I2C


    // Initialize the I2C peripheral

	rcc_periph_clock_enable(RCC_I2C1);


    i2c_peripheral_enable(I2C1);

    i2c_set_speed(I2C1,i2c_speed_fm_400k,2 );

    // Send a start condition on the I2C bus
    i2c_send_start(I2C1);

    // Send the WSEN-TIDS temperature sensor address
    i2c_send_7bit_address(I2C1, WSEN_TIDS_ADDRESS, I2C_WRITE);

    // Send the temperature register address
    i2c_send_data(I2C1, TEMPERATURE_REGISTER);
}





