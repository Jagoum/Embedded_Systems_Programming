/*
 * timer_driver.c
 *
 *  Created on: Jan 14, 2025
 *      Author: silvere
 */


#include "timer_driver.h"

/*
 *
 * These timer function are  used to cause a delay.
 *
 *
 */

void delay_us(uint16_t delay_us)
{
	uint16_t start = timer_get_counter(TIM2);
	while((timer_get_counter(TIM2) - start) < delay_us);
}

void delay_ms(uint16_t delay_ms)
{
	uint16_t i;
	for(i = 0; i < delay_ms; i++)
	{
		delay_us(1000);
	}
}

/* Sleep timer: 1us tick */
void timerConfig(void)
{
	rcc_clock_setup_pll(&rcc_clock_config[RCC_CLOCK_VRANGE1_HSI_PLL_24MHZ]);
	rcc_periph_clock_enable(RCC_TIM2);

	timer_set_period(TIM2, 240000); // Generate timer overflow event every 2ms
	timer_set_prescaler(TIM2,10 ); // Counter increment every 1us
	timer_set_mode(TIM2, TIM_CR1_CKD_CK_INT, TIM_CR1_CMS_EDGE, TIM_CR1_DIR_UP);
	timer_enable_counter(TIM2);
}




void adc_timerConfig(void)
{
	rcc_clock_setup_pll(&rcc_clock_config[RCC_CLOCK_VRANGE1_HSI_PLL_24MHZ]);
	rcc_periph_clock_enable(RCC_TIM3);

	timer_set_period(TIM3, 5000); // Generate timer overflow event every 2ms
	timer_set_prescaler(TIM3, 24000); // Counter increment every 1ms
	timer_set_mode(TIM3, TIM_CR1_CKD_CK_INT, TIM_CR1_CMS_EDGE, TIM_CR1_DIR_UP);
	timer_enable_counter(TIM3);
}


