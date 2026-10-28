# LEDstripController
Arduino based LED strip controller.  (Cycle through Christmas, autumn, or patriotic colors - or set to a solid color.)

# Arduino Mega RGB LED Controller — Schematic

## System Overview

```text
                   USB POWER SUPPLY
                         │
                      USB Cable
                         │
                         ▼
                 ┌─────────────────┐
                 │  ARDUINO MEGA  │
                 │                 │
                 │ PWM D10 ────────┼──────────────┐
                 │ PWM D11 ────────┼───────────┐  │
                 │ PWM D12 ────────┼────────┐  │  │
                 │                 │        │  │  │
                 │ GND ────────────┼────┐   │  │  │
                 └─────────────────┘    │   │  │  │
                                        │   │  │  │
                                        ▼   ▼  ▼  ▼
                                  ┌───────────────────┐
                                  │   MOSFET DRIVERS  │
                                  │                   │
                                  │  RED   GREEN BLUE │
                                  └────┬─────┬────┬────┘
                                       │     │    │
                                       │     │    │
                                       ▼     ▼    ▼
                                  ┌───────────────────┐
                                  │    RGB LED STRIP  │
                                  │                   │
                                  │  R    G    B   V+ │
                                  └──┬────┬────┬────┬─┘
                                     │    │    │    │
                                     │    │    │    │
                                     │    │    │    └─────────┐
                                     │    │    │              │
                                     │    │    │              │
                                     │    │    │              ▼
                                     │    │    │       V+ LED DC
                                     │    │    │       POWER SUPPLY
                                     │    │    │              │
                                     │    │    │              │
                                     ▼    ▼    ▼              │
                                  MOSFET LOAD OUTPUTS          │
                                     │    │    │              │
                                     └────┴────┴──────────────┤
                                                              │
                                                          PSU GND
                                                              │
                                                              └── Arduino GND
```

## Power Connections

### V+ LED Power Supply

* **V+:** Connect to the LED strip's V+ connection.
* **Negative (GND):** Connect to the ground/negative power terminals of all three MOSFET modules.
* The V+ supply powers the LED strip, not the Arduino Mega.

### Arduino Mega

* **USB:** Connect to a separate USB power supply to power the Arduino.
* **D10 (PWM):** Connect to the red-channel MOSFET control input.
* **D11 (PWM):** Connect to the green-channel MOSFET control input.
* **D12 (PWM):** Connect to the blue-channel MOSFET control input.
* **GND:** Connect to the power supply's negative terminal and the MOSFET control-ground reference, as required by the modules.

### MOSFET Driver Modules

Use one module for each RGB channel.

| Channel | Arduino PWM | LED Strip Connection |
| ------- | ----------- | -------------------- |
| Red     | D10         | R                    |
| Green   | D11         | G                    |
| Blue    | D12         | B                    |

Each MOSFET switches its corresponding color channel's current to ground. The LED strip's V+ remains connected directly to V+.

## Operating Principle

The Arduino generates PWM signals to control the three MOSFET modules independently. By varying the duty cycle of the red, green, and blue channels, the controller produces different colors, brightness levels, and animated transitions.

The Arduino and LED power supply have separate power paths. Their grounds share a common reference so the MOSFET control signals operate correctly.

**Important:** Verify the MOSFET modules' actual input and output terminal labels before wiring. This diagram assumes low-side switching modules compatible with the Arduino Mega's 5 V logic and PWM signals. Confirm that the modules support the required LED current.
