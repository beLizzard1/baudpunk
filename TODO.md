# TODOs for baudpunk

## USB/NCM
- [ ] Implement full CDC-NCM interface and data path
- [ ] Integrate MAC/IP assignment and DHCP (if needed)
- [ ] Forward received NCM packets to lwIP/netif

## USB Audio
- [ ] Implement USB audio ringbuffer logic for send/receive
- [ ] Add loopback test mode for audio
- [ ] Support stereo and different sample rates

## USB Composite Device (Audio + CDC-NCM)
- [ ] Finalize and test composite USB descriptor for:
    - UAC1 Microphone endpoint
    - UAC1 Speaker endpoint
    - CDC-NCM (Network Control Model) interface
- [ ] Validate enumeration and functionality on Windows, Linux, macOS, and Android hosts
- [ ] Implement robust error handling for USB setup requests
- [ ] Add documentation for each interface and endpoint in `components/usb_core/usb_descriptors.c`

### Descriptor Challenges
- Correctly interleaving Audio and CDC-NCM interfaces in the composite descriptor
- Ensuring host compatibility (Windows, Linux, macOS, Android) for both audio and network functions
- Handling alternate settings for audio streaming endpoints
- Synchronization and clocking between endpoints
- Descriptor size and alignment constraints for TinyUSB and ESP-IDF
- Host-specific quirks:
    - Android may require specific subclass/protocol values for audio devices to be recognized
    - Windows may need INF files or specific descriptors for composite devices
    - Ensuring both audio and network interfaces enumerate and function simultaneously on all platforms

## Modem
- [ ] Implement FSK modulation/demodulation
- [ ] Add AT command parser and shell
- [ ] Test softmodem over USB Audio

## General
- [ ] Improve README with usage examples
- [ ] Add CI build/test scripts
- [ ] Write unit tests for modem and USB logic

---
Add more tasks as the project evolves!
