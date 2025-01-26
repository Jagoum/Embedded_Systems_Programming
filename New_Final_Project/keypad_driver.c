/*
 * keypad_driver.c
 *
 *  Created on: Jan 17, 2025
 *      Author: jagoum
 */

#include "keypad_driver.h"

// Initialize keypad

void key_init(keypadconfig_t *config)
{
	rcc_periph_clock_enable(PORTA_BASE);

	//CONFIGURING ROWS AS INPUT

	for(int i=0; i<4; i++)

	{
		gpio_mode_setup(PORTA, GPIO_MODE_INPUT, GPIO_PUPD_PULLUP, config->row[i] );

	}

	// this is to configure the columns as output pins using gpio_mode_set in a for loop
	for(int i=0; i<4; i++)
	{
		gpio_mode_setup(PORTA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, config->col[i]);

	}

	// this function is to check if a row is pressed
	for(int row = 0; row < 4 ; row++)
	{
		// WHEN A KEY IS PRESSED, THE FLAG IS SET TO PULLDOWN SINCE INITAILLY IT WAS PULLUP
		// SO IF THAT IS THE CASE WE RESET IS AGAIN AND THIS MEANS THAT A KEY HAS BEING PRESSED

		if(!gpio_get(PORTA, config->row[i]));
		{
			gpio_set(PORTA, config->row[i]);

			//this line is responsible for mapping key pressed on the keypad to the corresponding key on the key map
			return config->keysfigure[row * 4 + col ];
		}

	}

}




