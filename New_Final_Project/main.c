#include "Drivers/global.h"
#include "Drivers/i2c_driver.h"
#include "Drivers/usart_driver.h"







//  int i;
//
//int main(void) {
//
//
//
//    while (1) {
//
//
//    	usart_setting();
//
//    	i2c_setting();
//
//
//        // Receive the temperature data
//        uint8_t temperature_data[2];
//
//       i2c_send_data(I2C1, *temperature_data);
//
//        // Convert the temperature data to a temperature value
//        int16_t temperature = (temperature_data[0] << 8) | temperature_data[1];
//        float temperature_celsius = temperature / 16.0;
//
//        // Send the temperature data over the UART
//
//        char temperature_string[10];
//        sprintf(temperature_string, "%f", temperature_celsius);
//
//    	while(temperature_string[i] != '\0')
//    	{
//    		 usart_send_blocking(USART2, (uint8_t*)temperature_string);
//    		i++;
//    	}
//
//
//        // Wait for 2 second before reading the temperature again
//        for ( i = 0; i < 1000000*2; i++) {
//            __asm__("nop");
//        }
//    }
//
//    return 0;
//}
