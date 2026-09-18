/*
  IoT Based Pothole Detection & Alert System
  Arduino-side prototype code

  Based on the code shown in the supplied project report.
  Verify pin assignments against your physical circuit before use.
*/

#include <TinyGPS.h>
#include <LiquidCrystal.h>

TinyGPS gps;
float flat = 0;
float flon = 0;

// LCD
const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Ultrasonic
const int trigPin = 6;
const int echoPin = 7;

long duration;
int distance;

// Motors
int m1 = 2;
int m2 = 3;
int m3 = 4;
int m4 = 5;

// Buzzer
int buz = A0;

void read_gps() {
  bool newData = false;

  for (unsigned long start = millis(); millis() - start < 1000;) {
    while (Serial.available()) {
      char c = Serial.read();
      if (gps.encode(c)) {
        newData = true;
      }
    }
  }

  if (newData) {
    unsigned long age;
    gps.f_get_position(&flat, &flon, &age);
  }
}

void setup() {
  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.print("WELCOME");
  delay(1500);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("POTHOLE ROBOT");
  lcd.setCursor(0, 1);
  lcd.print("SYSTEM READY");
  delay(2000);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buz, OUTPUT);

  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);

  digitalWrite(buz, LOW);
}

void loop() {
  // Move forward by default
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);

  // Ultrasonic measurement
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  // Display distance
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("DIST:");
  lcd.print(distance);
  lcd.print("cm");

  // Pothole detection condition used in the supplied code
  if (distance > 10) {
    lcd.setCursor(0, 1);
    lcd.print("POTHOLE DETECTED!");

    digitalWrite(buz, HIGH);

    // Stop robot
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, LOW);

    delay(3000);

    // Read GPS
    read_gps();

    // Print alert and coordinates
    Serial.println("ALERT: POTHOLE DETECTED");
    Serial.print("Latitude: ");
    Serial.println(flat, 6);
    Serial.print("Longitude: ");
    Serial.println(flon, 6);

    Serial.print("MAP: https://www.google.com/maps?q=");
    Serial.print(flat, 6);
    Serial.print(",");
    Serial.println(flon, 6);

    digitalWrite(buz, LOW);
  }

  delay(300);
}
