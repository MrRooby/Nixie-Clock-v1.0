# Nixie Clock v1.0

A simple Arduino-based Nixie Clock project featuring:
- Time and date display
- Temperature and humidity readings
- Gas level alarm detection
- Bluetooth control and setup

## Table of Contents
1. [Introduction](#introduction)
2. [Features](#features)
3. [Hardware Setup](#hardware-setup)
4. [Software Setup](#software-setup)
5. [Bluetooth Application](#bluetooth-application)
6. [Schematic and Board Photos](#schematic-and-board-photos)
7. [Device Photos](#device-photos)
8. [License](#license)

## Introduction
This project displays the current time, date, temperature, and humidity on Nixie tubes. It also includes a gas sensor alarm and Bluetooth connectivity.

## Features
- Displays time in HH:MM format on Nixie tubes
- Shows date in DD-MM format
- Reads temperature and humidity via a DHT sensor
- Detects gas levels using an MQ-9 sensor
- Allows alarm configuration via Bluetooth
- Alerts with a buzzer and LEDs

## Hardware Setup
1. Connect the Nixie tubes to the high-voltage driver.
2. Wire the DHT and MQ-9 sensors to the respective Arduino pins.
3. Set up the buzzer and LEDs for alarms.
4. Attach a Bluetooth module (e.g., HC-05).

## Software Setup
1. Install the required Arduino libraries:
   - <Wire.h>
   - DHT sensor library
   - RTC library
2. Upload the code to your Arduino board.
3. Pair your Bluetooth module with the companion smartphone app to control alarms.

## Bluetooth Application
*(Insert a screenshot or photo of your Bluetooth app here)*

## Schematic and Board Photos
*(Insert schematics, PCB designs, or board photos here)*

## Device Photos
*(Insert pictures of the completed device here)*

## License
This project is released under the [MIT License](LICENSE).
