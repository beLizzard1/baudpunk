#pragma once

#ifdef __cplusplus
extern "C" {
#endif

// ========== Project Info ==========
#define BAUDPUNK_VERSION      "0.0.1"
#define BAUDPUNK_DEVICE_NAME  "baudpunk-esp32s3"

// ========== Modem Configuration ==========
#define MODEM_BAUD_RATE        1200
#define MODEM_SAMPLE_RATE_HZ   48000
#define MODEM_RX_BUFFER_SIZE   256
#define MODEM_TX_BUFFER_SIZE   256
#define MODEM_ENABLE_TEST_TONE 0

// ========== USB Audio ==========
#define USB_AUDIO_SAMPLE_RATE_HZ    48000
#define USB_AUDIO_NUM_CHANNELS      1
#define USB_AUDIO_BIT_RESOLUTION     16
#define USB_AUDIO_FRAME_SIZE        ((USB_AUDIO_NUM_CHANNELS * USB_AUDIO_BIT_RESOLUTION) / 8)

// ========== USB CDC-NCM ==========
#define NCM_DEVICE_MAC_ADDRESS { 0x02, 0x42, 0x41, 0x55, 0x44, 0x01 } // "B-A-U-D"
#define NCM_HOST_IP_ADDRESS    "192.168.69.1"
#define NCM_DEVICE_IP_ADDRESS  "192.168.69.2"
#define NCM_NETMASK            "255.255.255.0"

// ========== Debug Flags ==========
#define ENABLE_USB_DEBUG         1   // For TinyUSB-level events
#define ENABLE_USB_AUDIO_DEBUG   1   // For USB audio (ringbuffer, callbacks, etc.)
#define ENABLE_MODEM_DEBUG       1   // For modulation, demodulation, DSP loop
#define ENABLE_NCM_DEBUG         1   // For CDC-NCM init and interface status

#ifdef __cplusplus
}
#endif