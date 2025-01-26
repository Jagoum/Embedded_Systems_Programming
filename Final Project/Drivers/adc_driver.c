/*
 * adc_driver.c
 *
 *  Created on: Jan 14, 2025
 *      Author: silvere
 */

//
//#include "adc_driver.h"
//#include "timer_driver.h"
//
//
//
//void adcSetup(void)
//{
//	uint8_t channels[] = {ADC_CHANNEL_TEMP, ADC_CHANNEL_VREF};
//
//	rcc_periph_clock_enable(RCC_ADC1);
//	adc_power_off(ADC1);
//
//	adc_enable_temperature_sensor();
//	adc_set_clk_prescale(ADC_CCR_ADCPRE_BY2);
//	adc_set_continuous_conversion_mode(ADC1);
//	adc_set_right_aligned(ADC1);
//	adc_set_resolution(ADC1, ADC_CR1_RES_12BIT);
//	adc_set_sample_time(ADC1, ADC_CHANNEL_TEMP , ADC_SMPR_SMP_384CYC);
//	adc_set_sample_time(ADC1, ADC_CHANNEL_VREF , ADC_SMPR_SMP_384CYC);
//
//	adc_set_regular_sequence(ADC1, 2, channels);
//}
//
//
//void activateTempMesearement(void)
//{
//	if(!adc_get_flag(ADC1, ADC_SR_ADONS))
//	{
//		adc_power_on(ADC1);
//		delay_us(50);
//		adc_enable_temperature_sensor();
//	}
//}
//
//
//uint16_t getAdcRawData(void)
//{
//	uint16_t adc_raw = 0;
//	timer_set_counter(TIM2, 0);
//	adc_start_conversion_regular(ADC1);
//
//	while(!adc_get_flag(ADC1, ADC_SR_EOC))
//	{
//		if(timer_get_counter(TIM3) == 1000)
//		{
//			break;
//			/*printf("Timer elapsed: Conversion error");*/
//		}
//	}
//
//	adc_raw = adc_read_regular(ADC1);
//
//	return (adc_raw);
//}
//
//
//uint16_t get_Temperature(uint16_t adc_raw)
//{
//	uint16_t ret_val  = 0;
//
//	ret_val = COMPUTATION_TEMPERATURE_TEMP30_TEMP110(adc_raw);
//
//	return (ret_val);
//}


