/*
 * keypad.c
 *
 *  Created on: Jan 18, 2025
 *      Author: jagoum
 */

#include "keypad.h"
#include "global.h"

void key_setup(void)
{
	rcc_periph_clock_enable(PORTA);

	//SETING UP ROW AS INPUT PINS

	gpio_mode_setup(PORTA, GPIO_MODE_INPUT,GPIO_PUPD_PULLUP,ROW_PINS);
	gpio_mode_setup(PORTA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE,COL_PINS);

}

int key;
char key_scan()
{
	char keys[4][4] =
	{
			{'1', '2', '3', 'A'},
			{'4', '5', '6', 'B'},
			{'7', '8', '9', 'C'},
			{'*', '0', '#', 'D'}
	};
	uint8_t ROWS[4] = {P4, P5, P6, P7};
	uint8_t COLS[4] = {P0, P1, P2, P3};

	for(int row=0 ; row < 4; row ++)
	{

//		gpio_set(PORTA, ROW_PINS);

		gpio_clear(PORTA, COLS[row]);

		for(int col = 0; col < 4 ; col++)
		{
			uint8_t buttonPressed = gpio_get(PORTA, ROWS[col]);

			if(!(buttonPressed & gpio_get(PORTA, COLS[row]) ))
			{
				key = keys[row][col];
				return key;
			}
		}

	}


}



