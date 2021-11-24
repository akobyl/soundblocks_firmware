#include "button_driver.h"
#include "hal_gpio.h"
#include <stdbool.h>

void button_init(void)
{
    gpio_set_pin_direction(BUTTON1, GPIO_DIRECTION_IN);
}

bool button_pressed(void)
{
    return gpio_get_pin_level(BUTTON1);
}