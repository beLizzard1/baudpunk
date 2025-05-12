# 🌀 baudpunk
> An ESP32-S3 soft-modem lab for learning modulation, demodulation, and digital signaling over USB

[![ESP-IDF](https://img.shields.io/badge/ESP--IDF-v5.x-blue.svg)](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/)
[![ESP32-S3](https://img.shields.io/badge/Target-ESP32--S3-green.svg)](https://www.espressif.com/en/products/socs/esp32-s3)
[![USB Audio](https://img.shields.io/badge/USB-Audio-informational)](https://github.com/hathach/tinyusb)
[![CDC-NCM](https://img.shields.io/badge/USB-CDC--NCM-orange)](https://en.wikipedia.org/wiki/USB_communications_device_class#Network_control_model)
[![License: MIT](https://img.shields.io/badge/license-MIT-lightgrey.svg)](LICENSE)

---

## 🎯 Project Goal

**`baudpunk`** is an open, hands-on lab platform for experimenting with soft-modem and USB data-over-wire techniques on the **ESP32-S3**, focusing on:

- 📞 Recreating analog modem functionality in software (modulation + demodulation)
- 🔊 Transmitting modem signals over **USB Audio**
- 🌐 Creating USB virtual Ethernet devices using **CDC-NCM** (Network Control Model)
- 🧪 Learning about low-level signaling, framing, and protocols
- 🛜 Bridging retro concepts like AT commands and dial-up with modern USB gadgets

---

## 🛠 Supported Target Boards

This project is designed to work with ESP32-S3 boards, such as:

- [ESP32-S3 DevKitC-1](https://www.amazon.co.uk/dp/B0DHJZ1V81)
  - Features: Dual-core processor, USB OTG, Wi-Fi, Bluetooth LE
  - USB-C interface for power and data
  - Ideal for USB-based experiments and soft-modem applications

Ensure your board supports USB OTG functionality for full compatibility.

---

## 🧱 Architecture Overview

```
+-------------------+                     +-----------------------+
|     ESP32-S3      |                     |  Host (PC, Phone, etc)|
|-------------------|                     |-----------------------|
|     FreeRTOS      |                     |   USB Audio Class     |
|   TinyUSB Stack   |  <==>  USB Link     | USB CDC-NCM (Network) |
|  Softmodem Logic  |                     | Serial + Net Interface|
| NCM Bridge Layer  |                     +-----------------------+
+-------------------+
```

- USB Audio (UAC1/2) for emulated analog signaling
- USB CDC-NCM for virtual Ethernet networking
- Optional AT command shell or scripting hooks

---

## 📦 Project Structure

```
baudpunk/
├── main/          # App entry point and logic glue
├── components/
│   ├── tinyusb/   # TinyUSB integration
│   ├── modem/     # FSK/PSK modem signal logic
│   └── ncm/       # USB CDC-NCM interface logic
├── include/       # Shared headers
├── test/          # Unit tests (planned)
├── CMakeLists.txt
└── README.md
```

---

## 🚀 Quick Start

> Prerequisites: ESP-IDF v5.x, ESP32-S3 board, USB-C cable

```bash
# Clone the project
git clone https://github.com/yourusername/baudpunk.git
cd baudpunk

# Set up ESP-IDF environment
. $HOME/esp/esp-idf/export.sh
idf.py set-target esp32s3

# Build, flash, and monitor
idf.py build flash monitor
```

---

## 🔄 Planned Features

- ESP32-S3, FreeRTOS, TinyUSB environment
- USB Audio IN/OUT endpoints
- USB CDC-NCM virtual Ethernet gadget
- Audio softmodem: FSK mod/demod
- AT-style shell over CDC
- Wiresharkable packet debug over USB
- Phone-compatible USB modem simulation

---

## 📚 Learn More

- [TinyUSB on ESP32-S3](https://github.com/hathach/tinyusb)
- [CDC-NCM spec](https://en.wikipedia.org/wiki/USB_communications_device_class#Network_control_model)
- [Softmodem Basics](https://en.wikipedia.org/wiki/Softmodem)
- [Modulation Types](https://en.wikipedia.org/wiki/Modulation)

---

## 💻 License

Licensed under the MIT License. See [LICENSE](LICENSE) for details.

---

## 🧑‍💻 Contributing

Contributions, experiments, retro dial tones, and bug reports all welcome.