#include <Arduino.h>

#define BUTTON 25
#define LIGHT 33
#define YELLOW 12

void setup() {
  Serial.begin(115200);

  pinMode(BUTTON, INPUT);
  pinMode(YELLOW, OUTPUT);

  digitalWrite(YELLOW, LOW);
}

void loop() {
  if (digitalRead(BUTTON) == HIGH) {

    int value = analogRead(LIGHT);

    Serial.print("snapshot=");
    Serial.println(value);

    digitalWrite(YELLOW, HIGH);
    delay(100);
    digitalWrite(YELLOW, LOW);

    while (digitalRead(BUTTON) == HIGH) {
      delay(10);
    }
  }
}