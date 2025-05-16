#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include "freertos/FreeRTOS.h"
#include "esp_err.h"
#include "tusb.h"
#include "esp_log.h"
#include "esp_check.h"
#include "freertos/queue.h"
#include "freertos/ringbuf.h"

// ========== Public API ==========

/**
 * @brief Initialize the USB Audio Class 1 (UAC1) component
 * Sets up TinyUSB callbacks and ringbuffers.
 */
void usb_audio_init(void);

/**
 * @brief Enable or disable loopback test mode
 * When enabled, incoming audio is echoed back over the USB microphone stream.
 *
 * @param enable true to enable loopback, false to disable
 */
void usb_audio_set_loopback(bool enable);

/**
 * @brief Send audio data to the host (microphone interface)
 *
 * @param data Pointer to raw PCM frame(s)
 * @param len  Length in bytes (typically one frame = 192 bytes for mono 16-bit @ 48kHz)
 * @param timeout Timeout in FreeRTOS ticks
 * @return true on success, false on ringbuffer full
 */
bool usb_audio_send(const void *data, size_t len, TickType_t timeout);

/**
 * @brief Receive audio data from the host (speaker interface)
 *
 * @param buf Destination buffer
 * @param maxlen Maximum number of bytes to read
 * @param timeout Timeout in FreeRTOS ticks
 * @return Number of bytes copied into `buf`, or 0 on timeout/failure
 */
int usb_audio_receive(void *buf, size_t maxlen, TickType_t timeout);

#ifdef __cplusplus
}
#endif
