#include <Arduino.h>

#define BLUE 14

void setup() {
  Serial.begin(115200);

  pinMode(BLUE, OUTPUT);
  digitalWrite(BLUE, LOW);
}

void loop() {
  if (Serial.available() > 0) {

    char command = Serial.read();

    if (command == 'B') {
      digitalWrite(BLUE, HIGH);
      Serial.println("BLUE=1");
    }

    if (command == 'b') {
      digitalWrite(BLUE, LOW);
      Serial.println("BLUE=0");
    }
  }
}