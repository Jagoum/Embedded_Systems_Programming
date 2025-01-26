/*
 * adc_driver.h
 *
 *  Created on: Jan 14, 2025
 *      Author: silvere
 *
 *      Most of these macros and functions here are used to convert
 *      the temperature by calculating
 *
 *
 */

#ifndef DRIVERS_ADC_DRIVER_H_
#define DRIVERS_ADC_DRIVER_H_

#include "global.h"


#define TS_CAL1_REG 		((uint16_t*) ((uint32_t) 0x1FF800FA))
#define TS_CAL2_REG 		((uint16_t*) ((uint32_t) 0x1FF800FE))
#define CALIBRATION_SIZE 	1U

#define V_REF				((uint32_t) 3000)
#define VDDA_APPLI          ((uint32_t) 3300)
#define RANGE_12BITS 		((uint32_t) 4095)
#define ADC_DATA_REG		((0x40012400U + 0x58U))
#define ADC_CHANNELS		2
#define ADC_SAMPLES			100

#define DMA_CHANNEL 1

#define COMPUTATION_DIGITAL_12BITS_TO_VOLTAGE(ADC_DATA) (((ADC_DATA) * VDDA_APPLI) / RANGE_12BITS)


/* Calculate temperature sensor value take n from the user manual formula
 *
 *this is to convert the analog input to a value in degree celcuis *
 * */

#define COMPUTATION_TEMPERATURE_TEMP30_TEMP110(TS_ADC_DATA)           \
  (((( ((int32_t)((TS_ADC_DATA * VDDA_APPLI) / V_REF)                 \
        - (int32_t) *TS_CAL1_REG)                                     \
     ) * (int32_t)(110 - 30)                                          \
    ) / (int32_t)(*TS_CAL2_REG - *TS_CAL1_REG)                        \
   ) + 30                                                             \
  )




void adcSetup(void);
void activateTempMesearement(void);
uint16_t get_Temperature(uint16_t adc_raw);
uint16_t getAdcRawData(void);


#endif /* DRIVERS_ADC_DRIVER_H_ */
