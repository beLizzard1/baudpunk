#include "baudpunk_config.h"        // Shared configuration constants

#include <stdio.h>                  // Standard I/O functions
#include "freertos/FreeRTOS.h"      // FreeRTOS task management
#include "freertos/task.h"
#include "esp_log.h"                // ESP logging macros
#include "tusb.h"                   // TinyUSB stack initialization
#include "esp_private/periph_ctrl.h" // Peripheral control
#include "driver/gpio.h"            // GPIO driver
#include "esp_err.h"                // ESP error codes

#include "usb_core.h"                // USB core initialization
#include "usb_audio.h"              // USB audio initialization
#include "usb_ncm.h"                // USB network control model initialization
#include "modem.h"                  // Modem task management
#include "baudpunk_banner.h"        // Banner printing function


static const char *TAG = "main";    // Tag for logging

void board_init(void);

void board_init(void) {
    ESP_LOGI(TAG, "Entering Board initialization.");
    // Initialize board-specific settings here

    // Enable USB peripheral and float D+/D- pins
    periph_module_enable(PERIPH_USB_MODULE);
    gpio_set_pull_mode(GPIO_NUM_19, GPIO_FLOATING);
    gpio_set_pull_mode(GPIO_NUM_20, GPIO_FLOATING);
    gpio_hold_dis(GPIO_NUM_19);
    gpio_hold_dis(GPIO_NUM_20);

    // For example, you can set up GPIOs, peripherals, etc.
    ESP_LOGI(TAG, "Leaving Board initialization.");
}

void app_main(void) {
    board_init(); // Initialize board-specific settings
    baudpunk_print_banner(); // Print the Baudpunk banner

    // Start polling task for TinyUSB
    xTaskCreatePinnedToCore(usb_device_task, "tusb_device_task", 4096, NULL, 5, NULL, 0);
        
    ESP_LOGI(TAG, "USB ready? %s", tud_ready() ? "Yes" : "No");

    // Initialize audio input (mic) and output (speaker)
    usb_audio_init();
    // xTaskCreate(usb_speaker_task, "usb_speaker_task", 4096, NULL, 5, NULL);
    // xTaskCreate(usb_mic_task, "usb_mic_task", 4096, NULL, 5, NULL);
    // Initialize modem task
    // xTaskCreate(modem_task, "modem_task", 4096, NULL, 5, NULL);

    // Initialize USB network control model
    usb_ncm_init();
    // xTaskCreate(usb_ncm_task, "usb_ncm_task", 4096, NULL, 5, NULL);

    ESP_LOGI(TAG, "System init complete.");
}