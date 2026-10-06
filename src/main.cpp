/*  ESP32-C6 Super Mini — тест: помигать реле (GPIO2) */

#include <Arduino.h>

#define RELAY_PIN  2

void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println("[TEST] Blink test started!");

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
}

void loop() {
  Serial.println("[TEST] Relay ON");
  digitalWrite(RELAY_PIN, HIGH);
  delay(500);

  Serial.println("[TEST] Relay OFF");
  digitalWrite(RELAY_PIN, LOW);
  delay(500);
}