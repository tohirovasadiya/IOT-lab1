#include <Arduino.h>

#define BUTTON 25
#define GREEN 27

bool greenState = false;
bool lastButtonState = LOW;

void setup() {
    pinMode(BUTTON, INPUT);
    pinMode(GREEN, OUTPUT);

    digitalWrite(GREEN, LOW);

    Serial.begin(115200);
}

void loop() {
    bool buttonState = digitalRead(BUTTON);

    // Tugma bosilganda
    if (buttonState == HIGH && lastButtonState == LOW) {

        greenState = !greenState;

        digitalWrite(GREEN, greenState);

        if (greenState) {
            Serial.println("GREEN=1");
        } else {
            Serial.println("GREEN=0");
        }

        delay(200); // button debounce
    }

    lastButtonState = buttonState;
}