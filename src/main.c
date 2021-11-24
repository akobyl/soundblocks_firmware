#include <FreeRTOS.h>
#include <task.h>

static TaskHandle_t xDemotask;

#include "driver_init.h"

#include "button_driver.h"

#define LED0 GPIO(GPIO_PORTB, GPIO_PIN(10))

static void demo_task(void *p)
{

    gpio_set_pin_direction(LED0, GPIO_DIRECTION_OUT);

    button_init();

    volatile int x = 0;
    bool button_level;

    for (;;)
    {
        button_level = button_pressed();
        gpio_set_pin_level(LED0, button_level);
        vTaskDelay(10);
        x += 1;
    }
}

int main(void)
{
    /* Initializes MCU, drivers and middleware */
    system_init();

    xTaskCreate(demo_task, "Demo", configMINIMAL_STACK_SIZE, NULL, 1, xDemotask);

    vTaskStartScheduler();
}
