#pragma once

#ifdef __cplusplus
extern "C" {
#endif

//--------------------------------------------------------------------+
// Board Specific Configuration
//--------------------------------------------------------------------+

// RHPort number used for device can be defined by board.mk, default to port 0
#ifndef BOARD_TUD_RHPORT
#define BOARD_TUD_RHPORT     0
#endif

// RHPort max operational speed can defined by board.mk
#ifndef BOARD_TUD_MAX_SPEED
#define BOARD_TUD_MAX_SPEED   OPT_MODE_DEFAULT_SPEED
#endif

//--------------------------------------------------------------------
// COMMON CONFIGURATION
//--------------------------------------------------------------------


// Define the mode for USB root hub port 0
#ifndef CFG_TUSB_RHPORT0_MODE
#define CFG_TUSB_RHPORT0_MODE     OPT_MODE_DEVICE // Set RHPort 0 to device mode
#endif

// This requires FreeRTOS
#ifndef CFG_TUSB_OS
#define CFG_TUSB_OS           OPT_OS_FREERTOS
#endif

// Espressif IDF requires "freertos/" prefix in include path
#if TUSB_MCU_VENDOR_ESPRESSIF
#define CFG_TUSB_OS_INC_PATH  freertos/
#endif

#define traceISR_EXIT_TO_SCHEDULER()

// can be defined by compiler in DEBUG build
#define CFG_TUSB_DEBUG        1

// Enable Device stack
#define CFG_TUD_ENABLED       1

// Default is max speed that hardware controller could support with on-chip PHY
#define CFG_TUD_MAX_SPEED     BOARD_TUD_MAX_SPEED

/* USB DMA on some MCUs can only access a specific SRAM region with restriction on alignment.
 * Tinyusb use follows macros to declare transferring memory so that they can be put
 * into those specific section.
 * e.g
 * - CFG_TUSB_MEM SECTION : __attribute__ (( section(".usb_ram") ))
 * - CFG_TUSB_MEM_ALIGN   : __attribute__ ((aligned(4)))
 */
#ifndef CFG_TUSB_MEM_SECTION
#define CFG_TUSB_MEM_SECTION
#endif

#ifndef CFG_TUSB_MEM_ALIGN
#define CFG_TUSB_MEM_ALIGN    __attribute__ ((aligned(4)))
#endif

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