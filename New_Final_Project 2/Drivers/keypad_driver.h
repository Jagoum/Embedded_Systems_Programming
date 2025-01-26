#ifndef KEYPAD_H
#define KEYPAD_H

#include <stdint.h>

/* GPIO Port and Pin Definitions */
#define ROW_PORT GPIOA
#define ROW_PINS (GPIO0 | GPIO1 | GPIO2 | GPIO3)
#define COL_PORT GPIOB
#define COL_PINS (GPIO0 | GPIO1 | GPIO2 | GPIO3)

/* Function Prototypes */
void keypad_init(void);
char keypad_scan(void);

#endif /* KEYPAD_H */
