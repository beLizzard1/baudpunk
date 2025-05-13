idf_component_register(
    SRCS "usb_audio.c"
    INCLUDE_DIRS "."
    PRIV_REQUIRES usb_core esp_ringbuf espressif__tinyusb
)