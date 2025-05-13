#include "tinyusb_init.c"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void) {
    // Initialize TinyUSB
    tinyusb_init();

    while (1) {
        // Handle TinyUSB tasks
        tinyusb_task();
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}