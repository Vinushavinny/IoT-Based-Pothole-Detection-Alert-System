# Implementation Notes

The supplied report/presentation contains two related implementation descriptions:

1. Arduino Uno + ultrasonic sensor + GPS + motor driver/motors + buzzer.
2. Wi-Fi/Telegram alert functionality using ESP32/ESP32-CAM terminology.

The code files in this repository are sanitized reproductions/adaptations of the code shown in the supplied project material. They are provided for documentation and repository completeness and have not been hardware-tested in this environment.

## Security

Credentials appearing in the source material were intentionally replaced with placeholders. Never commit real Wi-Fi passwords, Telegram bot tokens, API keys, or private credentials.

## Before Hardware Use

- Verify the exact board used in the physical prototype.
- Verify every GPIO/pin connection.
- Install the required Arduino libraries.
- Replace only the placeholders with your own local credentials.
- Test sensor readings through Serial Monitor before running the complete system.
