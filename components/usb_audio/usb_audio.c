#include "usb_audio.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"

static const char *TAG = "usb_audio";
static bool loopback_enabled = false;

void usb_audio_init(void)
{
    ESP_LOGI(TAG, "usb_audio_init() stub called.");
    // Stub: initialize ringbuffers, register TinyUSB callbacks, etc.
}

void usb_audio_set_loopback(bool enable)
{
    loopback_enabled = enable;
    ESP_LOGI(TAG, "Loopback mode %s", enable ? "ENABLED" : "DISABLED");
}

bool usb_audio_send(const void *data, size_t len, TickType_t timeout)
{
    ESP_LOGD(TAG, "usb_audio_send() called with %u bytes", (unsigned int)len);
    // Stub: pretend the data was enqueued for USB transfer
    return true;
}

int usb_audio_receive(void *buf, size_t maxlen, TickType_t timeout)
{
    ESP_LOGD(TAG, "usb_audio_receive() called (maxlen = %u)", (unsigned int)maxlen);
    // Stub: pretend no data was available
    return 0;
}
