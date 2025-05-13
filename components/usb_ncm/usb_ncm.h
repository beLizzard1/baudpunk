#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

void usb_ncm_init(void);

// This must match TinyUSB's declaration exactly
bool tud_network_recv_cb(const uint8_t *src, uint16_t size);

#ifdef __cplusplus
}
#endif
