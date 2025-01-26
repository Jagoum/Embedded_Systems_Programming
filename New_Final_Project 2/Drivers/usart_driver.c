#include "usart.h"
#include <libopencm3/stm32/usart.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/rcc.h>
#include "usart_driver.h"

/**
 * @brief Initialize USART1 for communication.
 */
void usart_init(void) {
    /* Enable clocks for GPIOA and USART1 */
    rcc_periph_clock_enable(RCC_GPIOA);
    rcc_periph_clock_enable(RCC_USART1);

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

    /* Enable USART1 */
    usart_enable(USART1);
}

/**
 * @brief Send a string over USART.
 * @param str The string to send.
 */
void usart_send_string(const char *str) {
    while (*str) {
        usart_send_blocking(USART1, *str++);
    }
}
