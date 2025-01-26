#include "Drivers/sensor_driver.h"
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/usart.h>
#include "Drivers/keypad_driver.h"
#include "Drivers/keymap.h"

void usart_setup(void) {
	//enabling usart clock

    rcc_periph_clock_enable(RCC_USART1);
    rcc_periph_clock_enable(RCC_GPIOA);

    /* Configure GPIO for USART1 TX (PA9) */
    gpio_mode_setup(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO9);
    gpio_set_af(GPIOA, GPIO_AF7, GPIO9);

    /* Configure USART1 */
    usart_set_baudrate(USART1, 9600);
    usart_set_databits(USART1, 8);
    usart_set_stopbits(USART1, USART_STOPBITS_1);
    usart_set_mode(USART1, USART_MODE_TX);
    usart_set_parity(USART1, USART_PARITY_NONE);
    usart_set_flow_control(USART1, USART_FLOWCONTROL_NONE);

    usart_enable(USART1);
}
void usart_send_string(const char *str) {

    while (*str) {
        usart_send_blocking(USART1, *str++);
    }
}

int main(void) {
    char buffer[50];

    /* Initialize peripherals */
    rcc_periph_clock_enable(RCC_GPIOB);
    mpu9250_init();
    usart_setup();

    while (1) {
        float temp = mpu9250_read_temperature();

        /* Format and send temperature to USART */
        snprintf(buffer, sizeof(buffer), "Temperature: %.2f°C\r\n", temp);
        usart_send_string(buffer);
    }

    return 0;
}
