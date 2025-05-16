idf_component_register(
    SRCS "usb_audio.c"
    INCLUDE_DIRS "."
    PRIV_REQUIRES esp_system driver usb_core esp_ringbuf espressif__tinyusb
)