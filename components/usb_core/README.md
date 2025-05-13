# 🧩 TinyUSB Integration for `baudpunk`

This component defines the USB stack setup and composite descriptors for the `baudpunk` project, using [TinyUSB](https://github.com/hathach/tinyusb).

## 🔧 Role in the Project

This component is responsible for:

- Initializing the TinyUSB stack (`tinyusb_init.c`)
- Defining the USB device descriptor (`usb_descriptors.c`)
- Providing a **composite configuration** that includes:
  - USB Audio Class 1 (full-duplex: speaker + microphone)
  - USB CDC-NCM (virtual Ethernet)

## 📂 Structure

tinyusb/
├── CMakeLists.txt          # Registers this component with ESP-IDF
├── usb_descriptors.c       # Composite USB descriptors (Audio + NCM)
├── usb_descriptors.h       # Interface IDs, endpoint definitions, format constants
└── README.md               # You're here

📦 Composite USB Layout
Interface #	Class	Direction	Description	Endpoint(s)
0	Audio Control	—	Audio function controller	—
1	Audio Streaming	OUT (host→ESP32)	Speaker interface (RX tones)	0x01
2	Audio Streaming	IN (ESP32→host)	Microphone interface (TX tones)	0x82
3	CDC-NCM Control	IN	Network control channel	0x83
4	CDC-NCM Data	IN/OUT	Virtual Ethernet data	0x84 / 0x04

📎 Notes
The USB descriptors are defined using TinyUSB's descriptor macros.
The configuration descriptor includes both audio and network class interfaces.
This component does not handle USB audio streaming or NCM data — those are implemented in usb_audio and usb_ncm.

📄 See Also
usb_audio — handles USB Audio streaming, ringbuffers, callbacks
usb_ncm — sets up CDC-NCM and future network bridging