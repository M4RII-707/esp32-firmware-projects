# ESP32 Firmware Projects

Hardware, firmware, and embedded systems projects built with ESP32, Arduino, and FPGA.

## Projects

### ESP32 Serial Parser + Watchdog
A command line interface over UART combined with a hardware watchdog timer.

**Hardware:** ESP32

**Commands:**
- `status` - prints free heap, uptime, and chip temperature
- `hang` - freezes the CPU to trigger the watchdog recovery

**What it demonstrates:**
- UART communication
- Character buffering and command parsing
- Watchdog fault tolerance and reboot reason reporting
