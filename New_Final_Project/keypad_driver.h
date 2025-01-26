/*
 * keypad_driver.h
 *
 *  Created on: Jan 17, 2025
 *      Author: jagoum
 */

#ifndef KEYPAD_DRIVER_H_
#define KEYPAD_DRIVER_H_


#include "Drivers/global.h"

typedef enum {

	ROW1 = GPIO0,
	ROW2 = GPIO1,
	ROW3 = GPIO2,
	ROW4 = GPIO3,
	COL1 = GPIO4,
	COL2 = GPIO5,
	COL3 = GPIO6,
	COL4 = GPIO7,

}keypads;

typedef struct {

	const char *keysfigure;
	uint16_t row[4];
	uint16_t col[4];
}keypadconfig_t;

typedef enum
{
	KEYPAD_NO_PRESS,
	KEYPAD_KEY_PRESSED,
}keypad_status;

typedef enum {
	PORTA_BASE = RCC_GPIOA,
	PORTB_BASE = RCC_GPIOB,
	PORTC_BASE = RCC_GPIOC,
	UART_BASE = RCC_USART2,
	PORTA = GPIOA,
	PORTB = GPIOB,
	PORTC = GPIOC,

}ePorts;


void key_init(keypadconfig_t *config);
char get_key_key(const keypadconfig_t *config);


#endif /* KEYPAD_DRIVER_H_ */
