#include "tusb_config.h"
#include "tusb.h"
#include "usb_descriptors.h"
#include "baudpunk_config.h"
#include <string.h>

void usb_device_task(void *param)
{
  (void)param;

  // init device stack on configured roothub port
  // This should be called after scheduler/kernel is started.
  // Otherwise it could cause kernel issue since USB IRQ handler does use RTOS queue API.
  tusb_rhport_init_t dev_init = {
      .role = TUSB_ROLE_DEVICE,
      .speed = TUSB_SPEED_AUTO};
  tusb_init(BOARD_TUD_RHPORT, &dev_init);

  
  // RTOS forever loop
  while (1)
  {
    // tinyusb device task
    tud_task();
  }
}


// Invoked when the device is mounted
void tud_mount_cb(void)
{
}

// Invoked when the device is unmounted
void tud_umount_cb(void)
{
}

// Invoked when the device is suspended
void tud_suspend_cb(bool remote_wakeup_en)
{
}

// Invoked when the USB bus is resumed
void tud_resume_cb(void)
{
}