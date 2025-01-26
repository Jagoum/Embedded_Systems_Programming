/*
 * uart_driver.h
 *
 *  Created on: Jan 15, 2025
 *      Author: silvere
 */

#ifndef DRIVERS_UART_DRIVER_H_
#define DRIVERS_UART_DRIVER_H_

#include <stdio.h>
#include <stdint.h>
#include <string.h>
/*
 * this libaries below are for standard error and standard output
 */

#include <errno.h>
#include <unistd.h>

/*
 * The uart_speed is necessary so that we can be able to communicate with other
 * devices tranfer information effectively
 *
 * the print char function is a function that that will help us to print infomation on the another device through uart communication medium
 *
 *
 */


#define USART_SPEED 400000U

void uart_config(void);
void print_char(char *st);



#endif /* DRIVERS_UART_DRIVER_H_ */
