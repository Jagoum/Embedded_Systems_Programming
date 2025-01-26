/*
 * gpio_driver.c
 *
 *  Created on: Jan 17, 2025
 *      Author: jagoum
 */

#include "Drivers/global.h"
#include "gpio_driver.h"
#include "keypad_driver.h"



//void gpio_config(void)
//{
//
//}


void gpio_enable_port(ePorts ports)

{

	switch(ports)

	{

	case PORTA:
		rcc_periph_clock_enable(PORTA);
		break;
	case PORTB:
		rcc_periph_clock_enable(PORTB);
		break;
	case PORTC:
		rcc_periph_clock_enable(PORTC);
		break;

	default:
		break;

	}



    // configuring gpio pins for i2c

    gpio_mode_setup(GPIOB, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO8 | GPIO9);
    gpio_set_af(GPIOB, GPIO_AF4, GPIO8 | GPIO9);

    }

