#include "esp_log.h"
#include "usb_ncm.h"
#include "tusb.h"
#include "class/net/net_device.h"

static const char *TAG = "usb_ncm";

void usb_ncm_init(void) {
    // TODO: init NCM interface
}

bool tud_network_recv_cb(const uint8_t *src, uint16_t size) {
    // TODO: forward to netif input or drop
    return true;
}
