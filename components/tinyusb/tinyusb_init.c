#include "tusb.h"
#include "baudpunk_config.h"

void tinyusb_init(void) {
    if (TINYUSB_ENABLED) {
        tusb_init();
    }
}

void tinyusb_task(void) {
    if (TINYUSB_ENABLED) {
        tud_task();
    }
}
