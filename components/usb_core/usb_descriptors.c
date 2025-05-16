#include "usb_descriptors.h"
#include "tusb.h"

#include "esp_log.h"
#include <stdio.h>
#include <stdarg.h>

void tu_log(const char* format, ...) {
    va_list args;
    va_start(args, format);
    printf("[TUSB] ");
    vprintf(format, args);
    va_end(args);
}

// Device descriptor
tusb_desc_device_t const desc_device = {
    .bLength = sizeof(tusb_desc_device_t),
    .bDescriptorType = TUSB_DESC_DEVICE,
    .bcdUSB = 0x0200,
    .bDeviceClass = 0xEF, // Miscellaneous
    .bDeviceSubClass = 0x02,
    .bDeviceProtocol = 0x01,
    .bMaxPacketSize0 = CFG_TUD_ENDPOINT0_SIZE,
    .idVendor = 0xCafe,
    .idProduct = 0x4000,
    .bcdDevice = 0x0100,
    .iManufacturer = 0x01,
    .iProduct = 0x02,
    .iSerialNumber = 0x03,
    .bNumConfigurations = 0x01
};

uint8_t const* tud_descriptor_device_cb(void) {
    return (uint8_t const*) &desc_device;
}

// Configuration descriptor (you'll want your real composite one here)
uint8_t const desc_configuration[] = {
    // Replace with your actual config descriptor
    9, TUSB_DESC_CONFIGURATION, 9, 0, 1, 1, 0, 0xC0, 50
};

uint8_t const* tud_descriptor_configuration_cb(uint8_t index) {
    (void) index;
    return desc_configuration;
}

// Strings
const char* string_desc_arr[] = {
    (const char[]){ 0x09, 0x08 },
    "baudpunk",
    "baudpunk USB Audio + CDC-NCM",
    "123456",
    "CDC-NCM Interface",
    "Audio Speaker",
    "Audio Microphone"
};

static uint16_t _desc_str[32];

uint16_t const* tud_descriptor_string_cb(uint8_t index, uint16_t langid) {
    (void) langid;

    uint8_t chr_count;

    if (index == 0) {
        _desc_str[1] = (string_desc_arr[0][1] << 8) | string_desc_arr[0][0];
        chr_count = 1;
    } else {
        if (index >= sizeof(string_desc_arr)/sizeof(string_desc_arr[0])) return NULL;

        const char* str = string_desc_arr[index];
        chr_count = strlen(str);
        if (chr_count > 31) chr_count = 31;
        for (uint8_t i = 0; i < chr_count; i++) {
            _desc_str[1 + i] = str[i];
        }
    }

    _desc_str[0] = (TUSB_DESC_STRING << 8) | (2 * chr_count + 2);
    return _desc_str;
}
