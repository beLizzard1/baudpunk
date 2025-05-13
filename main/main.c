#include <stdio.h>                  // printf (if used)
#include "freertos/FreeRTOS.h"      // For task management (if needed)
#include "esp_log.h"                // Logging macros
#include "tusb.h"              // tinyusb_driver_install()

#include "usb_audio.h"              // usb_audio_init()
#include "usb_ncm.h"                // usb_ncm_init()
#include "modem.h"                  // modem_start_task()
#include "baudpunk_config.h"        // shared config constants (if used)
#include "baudpunk_banner.h"         // baudpunk_print_banner()

static const char *TAG = "main";

void app_main(void) {

    baudpunk_print_banner();

    tusb_init();

    usb_audio_init();
    usb_ncm_init();
    modem_start_task();

    ESP_LOGI(TAG, "System init complete.");
}
