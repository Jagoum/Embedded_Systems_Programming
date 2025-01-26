#include "global.h"
#include "I2C_Driver.h"
#include "uart_driver.h"




int _write(int file, char *str, int len);
/*
 *
 * This driver is for temperature printing
 *
 */


void i2c_config(void)

{

	// this clock is to enable the i2c protocol.

	 rcc_periph_clock_enable(RCC_I2C1);

	 rcc_periph_clock_enable(RCC_GPIOB);

	 /*CONFIGURING I2C PINS AS ALTERNATE FUNCTIONS
	  *
	  *
	  */

		 gpio_mode_setup(GPIOB, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO8 | GPIO9);

		 gpio_set_af(GPIOB, GPIO_AF4, GPIO8|GPIO9);

		/*
		 * this is to enable communication with the sensor and the microcontroller
		 *
		 * the speed is set, the peripharal is first disabled so that error do not occur
		 */
		 i2c_peripheral_disable(I2C);

		 i2c_set_speed(I2C, i2c_speed_sm_100k, 400000);

		 i2c_peripheral_enable(I2C);

		 i2c_enable_ack(I2C);

		i2c_set_clock_frequency(I2C, 24);

		i2c_set_fast_mode(I2C);

		i2c_set_trise(I2C, 24);





}


//  this is to read the temperature of the sensor


uint8_t  i2c_read_register(uint8_t add, uint8_t regist, uint8_t* data)
{
//	uint8_t data;

	i2c_transfer7(I2C, add, &regist, 1, data , 1);

	return data;

}

float i2c_read_temperature(void)
{
	uint8_t reg = 0x1;

	uint8_t high_temp = i2c_read_register(I2C_SENSOR_ADDRESS, reg, I2C_REGISTER_ADDRESS);

	reg = 0x2;

	uint8_t low_temp = i2c_read_register(I2C_SENSOR_ADDRESS, reg, I2C_REGISTER_ADDRESS);

    uint16_t raw_temp = (high_temp << 8) | low_temp;

    // Convert raw temperature to degrees Celsius
    float temperature = (raw_temp / 340.0) + 36.53;

    		return temperature;

}



