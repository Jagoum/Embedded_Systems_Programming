/*
 * timer_driver.h
 *
 *  Created on: Jan 14, 2025
 *      Author: silvere
 *
 *      this header file is to define the prototype of all the functions available
 *      on the configuration of of timers
 *      the delays are not really relevant .
 *
 */

#ifndef DRIVERS_TIMER_DRIVER_H_
#define DRIVERS_TIMER_DRIVER_H_

#include "global.h"



void timerConfig(void);
void adc_timerConfig(void);
void delay_us(uint16_t delay);
void delay_ms(uint16_t delay);


#endif /* DRIVERS_TIMER_DRIVER_H_ */
