/*
 * gpio_driver.h
 *
 *  Created on: Jan 17, 2025
 *      Author: jagoum
 */


#ifndef DRIVERS_GPIO_DRIVER_H_
#define DRIVERS_GPIO_DRIVER_H_

#include "global.h"
#include "usart_driver.h"
#include "keypad_driver.h"

void gpio_config(void);



typedef enum {

	ROW_1 = GPIO4,
	ROW_2 = GPIO13,
	ROW_3 = GPIO14,
	ROW_4 = GPIO15,
	COL_1 = GPIO6,
	COL_2 = GPIO7,
	COL_3 = GPIO11,
	COL_4 = GPIO12,
}keypad_pins_t;


typedef struct
{

	 uint32_t port ;
	 uint16_t pin ;
	 uint32_t mode ;
	 uint32_t pupd;
	 uint32_t speed;

}gpio_pins_config;


void gpio_enable_port(ePorts ports);


#endif /* DRIVERS_GPIO_DRIVER_H_ */
