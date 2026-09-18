/*
  ESP32 Telegram Alert Bridge

  Sanitized version of the Telegram/Wi-Fi code shown in the supplied
  project material. Real credentials are intentionally NOT included.

  Required libraries:
    - WiFi
    - WiFiClientSecure
    - UniversalTelegramBot

  Set your credentials locally before use.
*/

#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

#define BOTtoken "YOUR_TELEGRAM_BOT_TOKEN"
#define CHAT_ID "YOUR_TELEGRAM_CHAT_ID"

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

String serialData = "";

void setup() {
  Serial.begin(9600);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  client.setInsecure();

  bot.sendMessage(CHAT_ID, "ESP32 Telegram System Started", "");
}

void loop() {
  while (Serial.available()) {
    char c = Serial.read();

    if (c == '\n') {
      if (serialData.length() > 0) {
        Serial.println("Sending to Telegram...");
        bot.sendMessage(CHAT_ID, serialData, "");
        serialData = "";
      }
    } else {
      serialData += c;
    }
  }
}
