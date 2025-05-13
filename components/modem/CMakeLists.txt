idf_component_register(
    SRCS "modem.c"
    INCLUDE_DIRS "."
    PRIV_REQUIRES usb_core espressif__tinyusb
    )