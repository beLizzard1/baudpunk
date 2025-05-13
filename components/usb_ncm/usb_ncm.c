#include "esp_log.h"
#include "usb_ncm.h"

static const char *TAG = "usb_ncm";

void usb_ncm_init(void) {
    ESP_LOGI(TAG, "USB CDC-NCM stub initialized.");
    // In future: register endpoints, manage link status, pass SLIP/PPP
}