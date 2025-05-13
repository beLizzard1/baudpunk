#pragma once

// Audio format

// Aliases for descriptor config macros
#define USB_AUDIO_SAMPLE_RATE_HZ    USB_AUDIO_SAMPLE_RATE_HZ
#define USB_AUDIO_NUM_CHANNELS      USB_AUDIO_NUM_CHANNELS
#define USB_AUDIO_BIT_RESOLUTION    USB_AUDIO_BIT_RESOLUTION
#define AUDIO_FRAME_SIZE            USB_AUDIO_FRAME_SIZE

// Interface numbers
enum {
    ITF_NUM_AUDIO_CONTROL = 0,
    ITF_NUM_AUDIO_STREAM_SPK,   // OUT (host → ESP32)
    ITF_NUM_AUDIO_STREAM_MIC,   // IN  (ESP32 → host)
    ITF_NUM_CDC_NCM_CONTROL,
    ITF_NUM_CDC_NCM_DATA,
    ITF_NUM_TOTAL
};

// Endpoint numbers
#define EPNUM_AUDIO_SPK_OUT    0x01
#define EPNUM_AUDIO_MIC_IN     0x82
#define EPNUM_CDC_NOTIFY       0x83
#define EPNUM_CDC_OUT          0x04
#define EPNUM_CDC_IN           0x84

#ifdef __cplusplus
extern "C" {
#endif

// Optional: function declarations for descriptor callbacks
const uint8_t* tud_descriptor_device_cb(void);
const uint8_t* tud_descriptor_configuration_cb(uint8_t index);
const uint16_t* tud_descriptor_string_cb(uint8_t index, uint16_t langid);

#ifdef __cplusplus
}
#endif