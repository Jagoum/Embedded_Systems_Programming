/*
 * keymap.c
 *
 *  Created on: Jan 17, 2025
 *      Author: jagoum
 */


#include "global.h"
#include "keymap.h"
#include "keypad_driver.h"

#define UART_SPEED 9600
static const char  keymap[16]= {
		'1', '2', '3', 'A',
		'4', '5', '6', 'B',
		'7', '8', '9', 'C',
		'*', '0', '#', 'D'

};

keypadconfig_t keymap_setup =
{
		.keysfigure = keymap,
		.row = { ROW1, ROW2, ROW3, ROW4 },
		.col ={COL1 , COL2, COL3, COL4 },

};

void usart_setup(void)
{
	rcc_periph_clock_enable(UART_BASE);
	rcc_periph_clock_enable(PORTA_BASE);
	usart_set_baudrate(USART2, UART_SPEED);
	usart_set_databits(USART2, 8);
	usart_set_flow_control(USART2, USART_FLOWCONTROL_NONE);
	usart_set_mode(USART2, USART_MODE_TX);
	usart_set_parity(USART2, USART_PARITY_NONE);
	usart_set_stopbits(USART2, USART_STOPBITS_1);

	gpio_mode_setup(PORTA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO2);
	gpio_set_af(PORTA , GPIO_AF7, GPIO2);

	usart_enable(USART2);
}

void usart_send_string(const char *str)
{
	while(*str)
	{
		usart_send_blocking(USART2, *str++);
	}

}

int main()
{

rcc_periph_clock_enable(PORTB_BASE);

key_init(keymap_setup.keysfigure);
usart_setup();

while(1){

	char key = key_init(keymap_setup.row++);

	if(key != '\0')
	{
		usart_send_string("key Pressed: ");
		usart_send_blocking(USART2, key);
		usart_send_string("\r\n");
	}
}
return 0;
}



