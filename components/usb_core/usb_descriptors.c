#ifndef traceISR_EXIT_TO_SCHEDULER
// Avoid dependency on missing FreeRTOS trace macro in ESP-IDF
#define traceISR_EXIT_TO_SCHEDULER()
#endif

#include "tusb_config.h"
#include "tusb.h"
#include "usb_descriptors.h"
#include "baudpunk_config.h"
#include <string.h>

// USB Device Descriptor
tusb_desc_device_t const desc_device = {
    .bLength            = sizeof(tusb_desc_device_t),
    .bDescriptorType    = TUSB_DESC_DEVICE,
    .bcdUSB             = 0x0200,
    .bDeviceClass       = 0xEF, // Misc (IAD)
    .bDeviceSubClass    = 0x02,
    .bDeviceProtocol    = 0x01,
    .bMaxPacketSize0    = CFG_TUD_ENDPOINT0_SIZE,

    .idVendor           = 0xCafe,
    .idProduct          = 0x4000,
    .bcdDevice          = 0x0100,

    .iManufacturer      = 0x01,
    .iProduct           = 0x02,
    .iSerialNumber      = 0x03,

    .bNumConfigurations = 0x01
};

// Helper macro: calculate frame size in bytes (channels × resolution / 8)
#define AUDIO_FRAME_SIZE_BYTES  ((USB_AUDIO_NUM_CHANNELS * USB_AUDIO_BIT_RESOLUTION) / 8)
#define AUDIO_FRAME_SIZE_LO     (AUDIO_FRAME_SIZE_BYTES & 0xFF)
#define AUDIO_FRAME_SIZE_HI     ((AUDIO_FRAME_SIZE_BYTES >> 8) & 0xFF)

// Configuration Descriptor Length
#define CONFIG_TOTAL_LEN (TUD_CONFIG_DESC_LEN + \
                          8 + 9 + 9 + 9 + 7 +     /* Audio OUT IAD + AC + AS0 + AS1 + EP */ \
                          9 + 9 + 7 +             /* Audio IN AS0 + AS1 + EP */ \
                          TUD_CDC_NCM_DESC_LEN)   /* CDC-NCM */

// Static Composite Configuration Descriptor
uint8_t const desc_configuration[] = {
    // Configuration Descriptor
    TUD_CONFIG_DESCRIPTOR(1, ITF_NUM_TOTAL, 0, CONFIG_TOTAL_LEN, 0x80, 50),

    // ----- Audio Speaker (OUT) -----
    // Interface Association (IAD) for Audio
    0x08, TUSB_DESC_INTERFACE_ASSOCIATION, ITF_NUM_AUDIO_CONTROL, 2, TUSB_CLASS_AUDIO, 0x00, 0x00, 0,

    // Audio Control Interface
    0x09, TUSB_DESC_INTERFACE, ITF_NUM_AUDIO_CONTROL, 0x00, 0x00, TUSB_CLASS_AUDIO, 0x01, 0x00, 0,

    // Audio Streaming Interface (Alt 0) - Zero Bandwidth
    0x09, TUSB_DESC_INTERFACE, ITF_NUM_AUDIO_STREAM_SPK, 0x00, 0x00, TUSB_CLASS_AUDIO, 0x02, 0x00, 0,

    // Audio Streaming Interface (Alt 1) - Operational
    0x09, TUSB_DESC_INTERFACE, ITF_NUM_AUDIO_STREAM_SPK, 0x01, 0x01, TUSB_CLASS_AUDIO, 0x02, 0x00, 0,

    // Isochronous OUT Endpoint Descriptor (Speaker)
    0x07, TUSB_DESC_ENDPOINT, EPNUM_AUDIO_SPK_OUT, 0x01, AUDIO_FRAME_SIZE_LO, AUDIO_FRAME_SIZE_HI, 0x01,

    // ----- Audio Microphone (IN) -----
    // Audio Streaming Interface (Alt 0) - Zero Bandwidth
    0x09, TUSB_DESC_INTERFACE, ITF_NUM_AUDIO_STREAM_MIC, 0x00, 0x00, TUSB_CLASS_AUDIO, 0x02, 0x00, 0,

    // Audio Streaming Interface (Alt 1) - Operational
    0x09, TUSB_DESC_INTERFACE, ITF_NUM_AUDIO_STREAM_MIC, 0x01, 0x01, TUSB_CLASS_AUDIO, 0x02, 0x00, 0,

    // Isochronous IN Endpoint Descriptor (Mic)
    0x07, TUSB_DESC_ENDPOINT, EPNUM_AUDIO_MIC_IN, 0x01, AUDIO_FRAME_SIZE_LO, AUDIO_FRAME_SIZE_HI, 0x01,

    // ----- CDC-NCM -----
    TUD_CDC_NCM_DESCRIPTOR(
        ITF_NUM_CDC_NCM_CONTROL, // Control interface
        4,                       // MAC string index
        0,                       // Embedded MAC string index (optional)
        EPNUM_CDC_NOTIFY,
        8,
        EPNUM_CDC_OUT,
        EPNUM_CDC_IN,
        64,
        1514),
};

// String Descriptors
char const* string_desc_arr[] = {
    (const char[]) { 0x09, 0x04 }, // LangID = English (0x0409)
    "baudpunk",                    // Manufacturer
    "Softmodem + USB Network",     // Product
    "123456",                      // Serial Number
    "Audio Interface",             // Audio
    "Network Interface"            // NCM
};

static uint16_t _desc_str[32];

// Descriptor Callbacks
const uint8_t* tud_descriptor_device_cb(void) {
    return (const uint8_t*) &desc_device;
}

const uint8_t* tud_descriptor_configuration_cb(uint8_t index) {
    (void) index;
    return desc_configuration;
}

const uint16_t* tud_descriptor_string_cb(uint8_t index, uint16_t langid) {
    (void) langid;

    if (index == 0) {
        _desc_str[0] = (TUSB_DESC_STRING << 8) | (2 + 2);
        _desc_str[1] = 0x0409;
        return _desc_str;
    }

    if (index >= sizeof(string_desc_arr) / sizeof(string_desc_arr[0])) {
        return NULL;
    }

    const char* str = string_desc_arr[index];
    size_t len = strlen(str);
    if (len > 31) len = 31;

    _desc_str[0] = (TUSB_DESC_STRING << 8) | ((len * 2) + 2);
    for (size_t i = 0; i < len; i++) {
        _desc_str[1 + i] = str[i];
    }

    return _desc_str;
}
