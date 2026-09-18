# IoT Based Pothole Detection & Alert System

An IoT-based prototype for real-time pothole detection, location tracking, and alert generation using an Arduino-based sensing system, GPS, Wi-Fi communication, and a mobile/Telegram alert workflow.

## Project Overview

Road potholes can create safety risks for drivers and pedestrians. This project proposes an automated system that detects road-surface irregularities using ultrasonic sensing, obtains location information through GPS, and communicates an alert through IoT connectivity.

The supplied project documents describe an Arduino Uno based prototype with an ultrasonic sensor, GPS module, motor driver and motors, buzzer, and Wi-Fi/IoT communication. The documents also describe ESP32-CAM/Telegram functionality for capturing and transmitting pothole information.

## Key Features

- Ultrasonic distance-based pothole detection
- GPS latitude and longitude acquisition
- Buzzer alert when a pothole is detected
- Robot/prototype movement using motor driver and motors
- Wi-Fi/IoT communication
- Telegram-based alert workflow described in the project material
- Circuit diagram and system architecture included in `images/`

## Hardware Components

- Arduino Uno
- Ultrasonic sensor(s)
- GPS module
- Motor driver
- DC motors
- ESP8266 Wi-Fi module
- ESP32-CAM (described in the project documents)
- Buzzer
- Jumper wires and related components
- Power supply

## Software

- Arduino IDE
- Arduino C / Embedded C
- TinyGPS library
- LiquidCrystal library
- Wi-Fi / Telegram libraries for the IoT alert portion
- Serial Monitor for testing

## System Workflow

1. The ultrasonic sensor measures the road-surface distance.
2. Arduino Uno receives and processes the sensor reading.
3. A threshold condition is used to identify a possible pothole.
4. The robot can be stopped and the buzzer activated when the condition is detected.
5. GPS data is read to obtain latitude and longitude.
6. The location information is printed through the serial interface.
7. The IoT communication section forwards alert data through Wi-Fi/Telegram according to the supplied implementation.

> **Implementation note:** The supplied documents contain both an ESP8266-based hardware list and an ESP32/ESP32-CAM-based Telegram implementation. These are retained as documented rather than silently changing the original project description.

## Repository Structure

```text
IoT-Based-Pothole-Detection-Alert-System/
├── README.md
├── LICENSE
├── .gitignore
├── code/
│   ├── arduino_pothole_detector.ino
│   └── esp32_telegram_bridge.ino
├── hardware/
│   └── components.md
├── images/
│   ├── system-architecture.png
│   └── circuit-diagram.png
└── docs/
    ├── project-report.pdf
    ├── project-review.pdf
    ├── project-presentation.pptx
    └── implementation-notes.md
```

## Project Team

- Sampath Srinivas — 23BCE7414
- Vaishnavi — 23BCE9869
- K. Rama Ganesh — 23BCE7277
- Sk Rizwana — 23BEC7373
- I. Vinusha — 23BEC7371
- Tejesh Madanwad — 23BCE7365

**Guide:** Prof. Shaik Subhani  
**University:** VIT-AP University

## My Contribution

I contributed to both the hardware and software aspects of the project. I worked on hardware assembly, sensor interfacing, circuit connections, Arduino-based implementation, ultrasonic sensor readings, pothole detection logic, GPS data handling, serial communication, IoT communication, testing, and troubleshooting.

## Future Scope

- Integration with autonomous vehicles
- Data analytics for predictive maintenance
- Additional depth sensors or cameras
- A dedicated mobile application and pothole map
- Larger-scale deployment for road-condition monitoring

## Important Security Note

The original project material contains Wi-Fi credentials and a Telegram bot token. **Do not upload those secrets to GitHub.** The code in this repository uses placeholders instead.

If the credentials shown in the original documents were real and have ever been used, change/rotate them before making the repository public.

## Disclaimer

This repository is a project documentation/prototype repository based on the supplied project materials. Hardware wiring, libraries, pin assignments, and IoT configuration should be verified against the actual prototype before deployment.
