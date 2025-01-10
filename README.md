# Nixie Clock v1.0

A simple ESP32-based Nixie Clock project featuring:
- Time and date display
- Temperature and humidity readings
- Gas level alarm detection
- Bluetooth control for alarm clock

## Table of Contents
1. [Introduction](#introduction)
2. [Features](#features)
3. [Hardware Setup](#hardware-setup)
4. [Bluetooth Application](#bluetooth-application)
5. [Schematic and Board Photos](#schematic-and-board-photos)
6. [Device Photos](#device-photos)

## Introduction
This project displays the current time, date, temperature, and humidity on Z573M Nixie tubes. It also includes a gas sensor alarm, and Bluetooth set alarm clock connectivity.

## Features
- Displays time in HH:MM format on Nixie tubes
- Shows date in DD-MM format
- Reads temperature and humidity via a DHT22 sensor
- Detects gas levels using an MQ-9 sensor
- Allows alarm configuration via Bluetooth
- Alerts with a buzzer and LEDs

## Hardware Setup
1. Nixie tubes are connected to 170V and are driven via K155ID.
2. Drivers responsible for the lamps are connected to ESP32 via Level Shifters (3.3V to 5V)
3. Two of the drivers are connected to PCF8575 I2C port expander.
4. RTC clock is connected to the board for time keeping
5. DHT and MQ-9 sensors are connected directly to the ESP32 pins.
6. Buzzer and LEDs are connected directly to the ESP32

## Bluetooth Application
*(pending)*

## Schematic and Board Photos
*(pending)*

## Device Photos
*(Insert pictures of the completed device here)*
