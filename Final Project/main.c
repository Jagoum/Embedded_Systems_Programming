#include "Drivers/timer_driver.h"
#include "Drivers/adc_driver.h"
#include "Drivers/uart_driver.h"
#include "Drivers/I2C_Driver.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

char temp_str[6];
int16_t temp;
float temperature;

int main(void)
{

	i2c_config();

//	i2c_clock_config();

	uart_config();

	timerConfig();

	//uart_config();


	while(1)
	{



		uint8_t key = key_scan();

		if(key != '\0')
		{
			printf("%c ", key);

		}



	     temperature = i2c_read_temperature();

	    sprintf(temp_str, "Temperature = %.2fC \r\n", (float)temperature);

		for (size_t i = 0; i < strlen(temp_str); i++)
			{
			    usart_send_blocking(USART2, temp_str[i]);
			}
	}
	return (0);
}
