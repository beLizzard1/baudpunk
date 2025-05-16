#include "usb_audio.h"


static const char *TAG = "usb_audio";

#define USB_AUDIO_RINGBUF_SIZE 2048

static RingbufHandle_t tx_ringbuf = NULL;  // To host
static RingbufHandle_t rx_ringbuf = NULL;  // From host

static bool loopback_enabled = false;

/**
 * @brief Initialize USB Audio device
 */
void usb_audio_init(void)
{
    ESP_LOGI(TAG, "Initializing USB Audio...");

    tx_ringbuf = xRingbufferCreate(USB_AUDIO_RINGBUF_SIZE, RINGBUF_TYPE_BYTEBUF);
    rx_ringbuf = xRingbufferCreate(USB_AUDIO_RINGBUF_SIZE, RINGBUF_TYPE_BYTEBUF);

    ESP_RETURN_ON_FALSE(tx_ringbuf && rx_ringbuf, , TAG, "Failed to create audio ring buffers");
    ESP_LOGI(TAG, "Audio ring buffers created");

    ESP_LOGI(TAG, "USB Audio initialized");
}

/**
 * @brief Enable or disable loopback mode
 *
 * @param enable true to enable loopback, false to disable
 */
void usb_audio_set_loopback(bool enable)
{
    loopback_enabled = enable;
    ESP_LOGI(TAG, "Loopback mode %s", enable ? "ENABLED" : "DISABLED");
}

/**
 * @brief Send audio data to the USB host
 *
 * @param data Pointer to PCM data
 * @param len  Data length in bytes
 * @param timeout Timeout in RTOS ticks
 * @return true if successfully queued, false if full
 */
bool usb_audio_send(const void *data, size_t len, TickType_t timeout)
{
    ESP_LOGD(TAG, "usb_audio_send(%u bytes)", (unsigned int)len);
    // TODO: Add ringbuf or USB write logic
    return true;
}

/**
 * @brief Receive audio data from the USB host
 *
 * @param buf Destination buffer
 * @param maxlen Max bytes to receive
 * @param timeout Timeout in RTOS ticks
 * @return Number of bytes received, 0 on timeout or error
 */
int usb_audio_receive(void *buf, size_t maxlen, TickType_t timeout)
{
    ESP_LOGD(TAG, "usb_audio_receive(maxlen=%u)", (unsigned int)maxlen);
    // TODO: Add ringbuf or USB read logic
    return 0;
}
