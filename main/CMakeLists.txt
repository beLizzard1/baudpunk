idf_component_register(SRCS "main.c" "baudpunk_banner.c"
                       INCLUDE_DIRS "."
                       REQUIRES usb_core usb_audio usb_ncm)
