#include "keypad_driver.h"
#include <libopencm3/stm32/gpio.h>

/* Keypad Mapping */
static const char keypad_map[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

/**
 * @brief Initialize the GPIO pins for the keypad.
 */
void keypad_init(void) {
    /* Configure rows as output */
    gpio_mode_setup(ROW_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, ROW_PINS);
    gpio_set_output_options(ROW_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_2MHZ, ROW_PINS);

    /* Configure columns as input with pull-up */
    gpio_mode_setup(COL_PORT, GPIO_MODE_INPUT, GPIO_PUPD_PULLUP, COL_PINS);
}

/**
 * @brief Scan the keypad for a pressed key.
 * @return char - The key value if pressed, '\0' otherwise.
 */
char keypad_scan(void) {
    for (int row = 0; row < 4; row++) {
        /* Set all rows high */
        gpio_set(ROW_PORT, ROW_PINS);

        /* Set the current row low */
        gpio_clear(ROW_PORT, (1 << row));

        /* Check each column for a key press */
        for (int col = 0; col < 4; col++) {
            if (!(gpio_get(COL_PORT, (1 << col)))) { // Column is low when key is pressed
                gpio_set(ROW_PORT, ROW_PINS); // Reset rows
                return keypad_map[row][col];
            }
        }
    }

    /* No key pressed */
    return '\0';
}
