# esp32c6-zigbee-relay

A minimal starting point for **Zigbee** firmware on the **ESP32-C6** with
PlatformIO and the Arduino framework, plus a relay on GPIO2 and a physical
button.

The interesting part of this repository is `platformio.ini`: getting the
Zigbee library to build for the C6 through PlatformIO is fiddly, and this file
is a known-good configuration.

## Why the special platform URL

The stock `platform = espressif32` entry in the PlatformIO registry lags behind
for the ESP32-C6 and the Zigbee stack, and builds against it frequently break.
This project pins the **pioarduino fork** instead:

```ini
platform = https://github.com/pioarduino/platform-espressif32/releases/download/stable/platform-espressif32.zip
```

Before building, check
[the releases page](https://github.com/pioarduino/platform-espressif32/releases)
for a newer release and update the URL if there is one.

## Configuration

```ini
framework = arduino
board = esp32-c6-devkitc-1
board_build.partitions = zigbee.csv    ; ships with the framework - leaves room for the Zigbee stack
build_flags = -D ZIGBEE_MODE_ED        ; End Device role
upload_port = COM10                    ; change to match your machine
monitor_port = COM10
```

`ZIGBEE_MODE_ED` selects the **End Device** role. Switch it to the coordinator
or router flag if you need a different role in your network.

## Current firmware

`src/main.cpp` is a hardware smoke test, not a finished application: it blinks
the relay on GPIO2 on and off every 500 ms and narrates each transition over
the serial port. Flash it first to confirm the board, the toolchain and your
relay wiring all work before writing the real Zigbee logic.

```cpp
#define RELAY_PIN 2
```

## Build and flash

```bash
pio run -t upload
pio device monitor        # 115200 baud
```

The partition table `zigbee.csv` is provided by the framework, so no path needs
to be set.

## Files

```
├── platformio.ini     # pioarduino platform, C6 board, Zigbee partition table
├── README.md
└── src/
    └── main.cpp       # relay smoke test on GPIO2
```

## Status and next steps

- [x] Board brings up and flashes via the pioarduino platform
- [x] PlatformIO settings that make `zigbee.csv` and `ZIGBEE_MODE_ED` build
- [ ] Replace the blink test with actual Zigbee On/Off cluster handling
- [ ] Add button-driven join/leave
- [ ] Report the relay state back to the coordinator

## License

No license file is included. Contact the author before redistributing.
