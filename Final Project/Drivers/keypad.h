/*
 * keypad.h
 *
 *  Created on: Jan 18, 2025
 *      Author: jagoum
 */

#ifndef DRIVERS_KEYPAD_H_
#define DRIVERS_KEYPAD_H_
#include "global.h"

#define PORTA GPIOA


#define P0 GPIO0
#define P1 GPIO1
#define P2 GPIO2
#define P3 GPIO3
#define P4 GPIO4
#define P5 GPIO5
#define P6 GPIO6
#define P7 GPIO7

#define ROW_PINS (GPIO4| GPIO13| GPIO14| GPIO15)
#define COL_PINS (GPIO6| GPIO7| GPIO11| GPIO12)

char key_scan(void);
void key_setup(void);




#endif /* DRIVERS_KEYPAD_H_ */
