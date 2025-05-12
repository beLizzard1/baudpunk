#pragma once

#ifdef __cplusplus
extern "C" {
#endif

// ========== General Project Info ==========
#define BAUDPUNK_VERSION "0.0.1"
#define BAUDPUNK_DEVICE_NAME "baudpunk-esp32s3"

// ========== Modem Configuration ==========

// Baud rate for simulated softmodem
#define MODEM_BAUD_RATE        1200

// Sample rate for audio-based modulation (Hz)
#define MODEM_SAMPLE_RATE_HZ   48000

// Size of modulation buffer (samples)
#define MODEM_BUFFER_SIZE      256

// Enable test tone (for debugging modem audio)
#define MODEM_ENABLE_TEST_TONE 0

// ========== USB Audio Configuration ==========

#define USB_AUDIO_SAMPLE_RATE_HZ    48000
#define USB_AUDIO_NUM_CHANNELS      1
#define USB_AUDIO_BIT_RESOLUTION    16

// ========== USB CDC-NCM Configuration ==========

// MAC address for NCM virtual network interface
#define NCM_MAC_ADDRESS     { 0x02, 0x00, 0x00, 0xBA, 0xUD, 0x01 }

// Host-side IP address for tethering tests
#define NCM_HOST_IP_ADDRESS "192.168.9.1"
#define NCM_DEVICE_IP_ADDRESS "192.168.9.2"

// ========== Debug Options ==========

#define ENABLE_USB_DEBUG       1
#define ENABLE_MODEM_DEBUG     1
#define ENABLE_NCM_DEBUG       1

#ifdef __cplusplus
}
#endif