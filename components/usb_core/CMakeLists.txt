idf_component_register(
    SRCS "usb_descriptors.c" "usb_core.c"
    INCLUDE_DIRS "." "../../include"
    PRIV_REQUIRES espressif__tinyusb esp_system driver usb_core usb_audio usb_ncm modem
)
add_compile_definitions(CFG_TUSB_DEBUG=2)

# Make the tusb_config.h from the project root available to tinyusb
idf_component_get_property(tinyusb_lib espressif__tinyusb COMPONENT_LIB)

# Add the project's top-level include/ to tinyusb's include search path
target_include_directories(${tinyusb_lib} PUBLIC "${PROJECT_DIR}/include")

# (Optional) If you need to force link some descriptors into tinyusb directly:
target_sources(${tinyusb_lib} PUBLIC "${COMPONENT_DIR}/usb_descriptors.c")