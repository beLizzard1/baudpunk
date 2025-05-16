#pragma once

#include "tusb.h"
#include "tusb_config.h"
#include "baudpunk_config.h"
#include <string.h>


// Language ID: English (United Kingdom)
#define USB_LANGID_EN_GB  0x0809

// Endpoint numbers (address | direction)
#define EPNUM_CDC_NOTIF    0x81
#define EPNUM_CDC_IN       0x82
#define EPNUM_CDC_OUT      0x02

#define EPNUM_AUDIO_SPK    0x03
#define EPNUM_AUDIO_MIC    0x83

// Interface numbers
enum {
  ITF_NUM_CDC_NCM_COMM = 0,
  ITF_NUM_CDC_NCM_DATA,
  ITF_NUM_AUDIO_CONTROL,
  ITF_NUM_AUDIO_STREAMING_SPK,
  ITF_NUM_AUDIO_STREAMING_MIC,
  ITF_NUM_TOTAL
};

// String descriptor indexes
enum {
  STRID_LANGID = 0,
  STRID_MANUFACTURER,
  STRID_PRODUCT,
  STRID_SERIAL,
  STRID_CDC,
  STRID_AUDIO_SPK,
  STRID_AUDIO_MIC,
  STRID_MAC_ADDRESS  // Optional, if needed for CDC-NCM
};

// Configuration descriptor total length (update manually if changed)
#define CONFIG_TOTAL_LEN (TUD_CONFIG_DESC_LEN + \
                          TUD_CDC_NCM_DESC_LEN + \
                          TUD_AUDIO_HEADSET_STEREO_DESC_LEN + \
                          101) // Estimated size of TUD_AUDIO_MIC_DESCRIPTOR

// Device descriptor
extern tusb_desc_device_t const desc_device;

// Configuration descriptor
extern uint8_t const desc_configuration[];

// String descriptors
extern const char* string_desc_arr[];