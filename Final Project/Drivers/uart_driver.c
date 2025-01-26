/*
 * uart_driver.c
 *
 *  Created on: Jan 15, 2025
 *      Author: silvere
 */

#include "uart_driver.h"
#include "global.h"

int _write(int file, char *ptr, int len);
/*
 * In ther uart_config function , we are activating the clock resposible for uart
 * we also activate the GPIOA clock since our sensor is connected to it
 *
 * the usart_set_baudrate() is used to set the speed at which the microcontorller is going to be transmitting infomation
 *
 * usart_set_databit() is to set the number of bit that should be transimitted using 8bit is easier
 *
 * the usart_set_mode() is to set the mode of communication ie simplex, duplex, half-duplex or simplex
 *
 * the parity set is to set parity bit that can be used for error checking using the function uart_set_parity()
 *
 *
 * the uart_set_stopbit
 *
 *
 */




void uart_config(void)
{
	rcc_periph_clock_enable(RCC_USART2);
	rcc_periph_clock_enable(RCC_GPIOA);

	usart_set_baudrate(USART2, USART_SPEED);
	usart_set_databits(USART2, 8);

	//if you are not setting any flow control you can still allow the function

	usart_set_flow_control(USART2, USART_FLOWCONTROL_NONE);

	usart_set_mode(USART2, USART_MODE_TX|USART_MODE_RX);

	usart_set_parity(USART2, USART_PARITY_NONE);

	usart_set_stopbits(USART2, USART_STOPBITS_1);


/*
 * CONFIGURING UART PIN AS ALTERNATE FUNCTIONS TO TRANSMIT AND RECIEVE DATA
 */

	gpio_mode_setup(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO2);

	gpio_set_af(GPIOA, GPIO_AF7, GPIO2|GPIO3);

	usart_enable(USART2);
}










void print_char(char *str)
{
	uint8_t i = 0;
	while(str[i] != '\0')
	{
		usart_send_blocking(USART2, (uint16_t *)str[i]);
		i++;
	}
}

/*
 * the _write() funcion is when you are defining a function without using a prototype
 * the usart_send_blocking() is used to send a message on the external device we are using to print our informations
 * this command can be typed on the command line if we want to diplay the values of our microcontroller on the screen
 *
 * " picocom /dev/ttyACM0 -b 9600 "
 *
 *
 * the content of this function below is used to display all the information as required on the screen.
 *
 */




int _write(int file, char *ptr, int len)
{
	int i;

	if (file == STDOUT_FILENO || file == STDERR_FILENO)
	{
		for (i = 0; i < len; i++) {
			if (ptr[i] == '\n') {
				usart_send_blocking(USART2, '\r');
			}
			usart_send_blocking(USART2, ptr[i]);
		}
		return i;
	}
	errno = EIO;
	return -1;
}
