#include <stdio.h>                  // printf (if used)
#include "freertos/FreeRTOS.h"      // For task management (if needed)
#include "esp_log.h"                // Logging macros
#include "tinyusb.h"                // tinyusb_driver_install()

#include "usb_audio.h"              // usb_audio_init()
#include "usb_ncm.h"                // usb_ncm_init()
#include "modem.h"                  // modem_start_task()
#include "baudpunk_config.h"        // shared config constants (if used)


void app_main(void) {

    baudpunk_print_banner();

    tinyusb_config_t tusb_cfg = {}; // Empty config uses callbacks
    tinyusb_driver_install(&tusb_cfg);

    usb_audio_init();
    usb_ncm_init();
    modem_start_task();

    ESP_LOGI(TAG, "System init complete.");
}
