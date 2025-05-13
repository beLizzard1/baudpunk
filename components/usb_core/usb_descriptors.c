#include "tusb_config.h"
#include "tusb.h"
#include "usb_descriptors.h"
#include "baudpunk_config.h"
#include <string.h>

// --------------------------------------------------------------------
// USB Device Descriptor
// --------------------------------------------------------------------

tusb_desc_device_t const desc_device = {
    .bLength            = sizeof(tusb_desc_device_t),
    .bDescriptorType    = TUSB_DESC_DEVICE,
    .bcdUSB             = 0x0200,
    .bDeviceClass       = 0xEF, // Miscellaneous (IAD)
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

const uint8_t* tud_descriptor_device_cb(void) {
    return (const uint8_t*) &desc_device;
}

// --------------------------------------------------------------------
// Configuration Descriptor
// --------------------------------------------------------------------

#define CONFIG_TOTAL_LEN \
    (TUD_CONFIG_DESC_LEN + \
     TUD_AUDIO_SPEAKER_DESC_LEN + \
     TUD_AUDIO_MIC_DESC_LEN + \
     TUD_CDC_NCM_DESC_LEN)

uint8_t const desc_configuration[] = {
    // Configuration header
    TUD_CONFIG_DESCRIPTOR(
        1,                      // Configuration number
        ITF_NUM_TOTAL,          // Total interfaces
        0,                      // String index
        CONFIG_TOTAL_LEN,       // Total length
        0x80,                   // Attributes (bus powered)
        50                      // Max power in 2mA units
    ),

    // Audio Speaker (OUT)
    TUD_AUDIO_SPEAKER_DESCRIPTOR(
        ITF_NUM_AUDIO_CONTROL,
        0x01, // Terminal ID
        ITF_NUM_AUDIO_STREAM_SPK,
        USB_AUDIO_SAMPLE_RATE_HZ,
        USB_AUDIO_NUM_CHANNELS,
        USB_AUDIO_BIT_RESOLUTION
    ),

    // Audio Microphone (IN)
    TUD_AUDIO_MIC_DESCRIPTOR(
        ITF_NUM_AUDIO_CONTROL,
        0x02, // Terminal ID
        ITF_NUM_AUDIO_STREAM_MIC,
        USB_AUDIO_SAMPLE_RATE_HZ,
        USB_AUDIO_NUM_CHANNELS,
        USB_AUDIO_BIT_RESOLUTION
    ),

    // CDC-NCM Interface
    TUD_CDC_NCM_DESCRIPTOR(
        ITF_NUM_CDC_NCM_CONTROL,
        4,                  // String index for MAC
        0,                  // Reserved (no embedded MAC)
        EPNUM_CDC_NOTIFY,
        8,                  // Notification EP size
        EPNUM_CDC_OUT,
        EPNUM_CDC_IN,
        64,                 // EP size
        1514                // Max segment size (Ethernet frame)
    )
};

const uint8_t* tud_descriptor_configuration_cb(uint8_t index) {
    (void) index;
    return desc_configuration;
}

// --------------------------------------------------------------------
// String Descriptors
// --------------------------------------------------------------------

char const* string_desc_arr[] = {
    (const char[]) { 0x09, 0x04 }, // 0: LangID = English
    "baudpunk",                    // 1: Manufacturer
    "Softmodem + USB Network",     // 2: Product
    "123456",                      // 3: Serial
    "MAC Interface",               // 4: CDC MAC
    "Audio Interface",             // 5: Audio
    "Network Interface"            // 6: NCM
};

static uint16_t _desc_str[32];

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
