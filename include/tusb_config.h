#pragma once

#ifdef __cplusplus
extern "C" {
#endif

// Required core config
#define CFG_TUSB_MCU               OPT_MCU_ESP32S3
#define CFG_TUSB_RHPORT0_MODE      OPT_MODE_DEVICE
#define CFG_TUSB_OS                OPT_OS_FREERTOS
#define CFG_TUSB_DEBUG             1

// Memory alignment
#define CFG_TUSB_MEM_SECTION
#define CFG_TUSB_MEM_ALIGN         __attribute__((aligned(4)))

// USB Classes enabled
#define CFG_TUD_CDC                1
#define CFG_TUD_AUDIO              1
#define CFG_TUD_NCM                1
#define CFG_TUD_MIDI               0
#define CFG_TUD_HID                0
#define CFG_TUD_MSC                0
#define CFG_TUD_NET_DEVICE         1
#define CFG_TUD_COMPOSITE          1

//--------------------------------------------------------------------
// AUDIO CONFIG
//--------------------------------------------------------------------

#define CFG_TUD_AUDIO_FUNC_1_CTRL_BUF_SZ  64
#define CFG_TUD_AUDIO_FUNC_1_N_AS_INT     2

// Use TinyUSB's default descriptor lengths for mono mic + mono speaker w/ feedback
#define TUD_AUDIO_MIC_DESC_LEN            TUD_AUDIO_MIC_ONE_CH_DESC_LEN
#define TUD_AUDIO_SPEAKER_DESC_LEN        TUD_AUDIO_SPEAKER_MONO_FB_DESC_LEN

#define CFG_TUD_AUDIO_FUNC_1_DESC_LEN \
    (TUD_AUDIO_MIC_DESC_LEN + TUD_AUDIO_SPEAKER_DESC_LEN)
//--------------------------------------------------------------------
// CDC CONFIG
//--------------------------------------------------------------------

#define CFG_TUD_CDC_RX_BUFSIZE     512
#define CFG_TUD_CDC_TX_BUFSIZE     512
#define CFG_TUD_CDC_EP_BUFSIZE     64

//--------------------------------------------------------------------
// NCM CONFIG
//--------------------------------------------------------------------

#define CFG_TUD_NCM_EP_BUFSIZE     1514

#ifdef __cplusplus
}
#endif