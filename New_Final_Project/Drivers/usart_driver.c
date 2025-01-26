/*
 * usart_driver.c
 *
 *  Created on: Jan 17, 2025
 *      Author: jagoum
 */

#include "usart_driver.h"
#include "global.h"
#include "gpio_driver.h"



    // Initialize the GPIO pins for UART


void usart_setting(void)
{
	//enabling the peripheral clock

//rcc_periph_clock_enable(RCC_USART2);

    // Initialize the UART peripheral


    usart_enable(USART2);
    usart_set_baudrate(USART2, usart_BAUDRATE);
    usart_set_databits(USART2, 8);
    usart_set_stopbits(USART2, 1);
    usart_set_parity(USART2, USART_PARITY_NONE);
   // usart_enable(USART2);
}



