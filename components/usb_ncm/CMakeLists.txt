idf_component_register(
    SRCS "usb_ncm.c"
    INCLUDE_DIRS "."
    PRIV_REQUIRES usb_core
)