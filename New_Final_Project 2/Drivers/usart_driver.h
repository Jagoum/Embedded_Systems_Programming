#ifndef USART_H
#define USART_H

#include <stdint.h>

#include <libopencm3/stm32/gpio.h>

/* Function Prototypes */
void usart_init(void);
//void usart_send_string(const char *str);


void usart_send_string(const char *str);
void usart_setup(void);

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

#endif /* USART_H */
