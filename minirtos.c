#include <stdio.h>

#include "pico/stdlib.h"
#include "hardware/gpio.h"

#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"

#define LED_PIN PICO_DEFAULT_LED_PIN

void TaskBlink(void *pvParameters)
{
    while (true)
    {
        gpio_put(LED_PIN, 1);
        sleep_ms(250);
        gpio_put(LED_PIN, 0);
        sleep_ms(750);
    }
}

int main()
{
    // Setup GPIO.
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    // Create the initial task.
    xTaskCreate(TaskBlink, "Blink", 128, NULL, 1, NULL);

    // Start the scheduler.
    // This never returns.
    vTaskStartScheduler();

    while (true)
    {
        // Program flow should not reach here.
    }
    
    return 0;
}
