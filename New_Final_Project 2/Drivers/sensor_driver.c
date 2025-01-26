#include "sensor_driver.h"
#include <libopencm3/stm32/i2c.h>
#include <libopencm3/stm32/gpio.h>

/* I2C Interface Settings */
#define I2C I2C1

/**
 * @brief Initialize I2C and MPU-9250 sensor.
 */
void mpu9250_init(void) {
    /* Enable I2C peripheral by activating their respective clock*/

    rcc_periph_clock_enable(RCC_I2C1);
    rcc_periph_clock_enable(RCC_GPIOB);

    /* Configure GPIO for I2C1 (PB8 -> SCL, PB9 -> SDA) */
    gpio_mode_setup(GPIOB, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO6 | GPIO7);

    gpio_set_output_options(GPIOB, GPIO_OTYPE_OD, GPIO_OSPEED_2MHZ, GPIO6 | GPIO7);

    gpio_set_af(GPIOB, GPIO_AF4, GPIO8 | GPIO9);

    /* Configure I2C settings */
    i2c_reset(I2C);
    i2c_peripheral_disable(I2C);
    i2c_set_clock_frequency(I2C, I2C_CR2_FREQ_24MHZ);
    i2c_set_fast_mode(I2C);
    i2c_set_dutycycle(I2C, I2C_CCR_DUTY_DIV2);

    i2c_set_ccr(I2C, 240); // this is the frequency if cimmunucation
    i2c_set_trise(I2C, 37);
    i2c_peripheral_enable(I2C);
}

/**
 * @brief Read raw temperature data from MPU-9250.
 * @return int16_t Raw temperature data.
 */
static int16_t mpu9250_read_temp_raw(void) {
    uint8_t *temp_h, *temp_l;

    /* Read TEMP_OUT_H */
    i2c_transfer7(I2C, MPU9250_ADDR, TEMP_OUT_H, 1, temp_h, 1);
    /* Read TEMP_OUT_L */
    i2c_transfer7(I2C, MPU9250_ADDR, TEMP_OUT_L, 1, temp_l, 1);

    /* Combine high and low bytes */
    return (int16_t)((temp_h << 8) | temp_l);
}

/**
 * @brief Read and calculate the temperature in Celsius.
 * @return float Temperature in Celsius.
 */
float mpu9250_read_temperature(void) {
    int16_t raw_temp = mpu9250_read_temp_raw();
    return (raw_temp / 333.87f) + 21.0f;
}

