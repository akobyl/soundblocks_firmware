#include <hal_gpio.h>

#define BUTTON1 GPIO(GPIO_PORTA, GPIO_PIN(25))

void button_init(void);
bool button_pressed(void);

