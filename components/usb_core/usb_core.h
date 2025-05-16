#pragma once

#ifdef __cplusplus
extern "C" {
#endif

// Task function for running the TinyUSB device task loop
void usb_device_task(void* param);

#ifdef __cplusplus
}
#endif
