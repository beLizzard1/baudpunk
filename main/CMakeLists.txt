idf_component_register(SRCS "main.c" "baudpunk_banner.c"
                       INCLUDE_DIRS "."
                       REQUIRES esp_system driver usb_core usb_audio usb_ncm modem espressif__tinyusb)

# Make the tusb_config.h from the project root available to tinyusb
idf_component_get_property(tinyusb_lib espressif__tinyusb COMPONENT_LIB)

# Add the project's top-level include/ to tinyusb's include search path
target_include_directories(${tinyusb_lib} PUBLIC "${PROJECT_DIR}/include")