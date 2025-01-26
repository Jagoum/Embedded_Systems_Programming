#ifndef SENSOR_DRIVER_H
#define SENSOR_DRIVER_H

#include <stdint.h>

/* MPU-9250 Register Definitions */
#define MPU9250_ADDR        0x68
#define TEMP_OUT_H          0x41
#define TEMP_OUT_L          0x42

/* Function Prototypes */
void mpu9250_init(void);
float mpu9250_read_temperature(void);

#endif /* SENSOR_DRIVER_H */
