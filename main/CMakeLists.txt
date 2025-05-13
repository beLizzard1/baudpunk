idf_component_register(SRCS "main.c"
                       INCLUDE_DIRS "."
                       REQUIRES tinyusb usb_audio cdc_ncm)
