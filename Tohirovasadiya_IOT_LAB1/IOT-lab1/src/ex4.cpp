#include <Arduino.h>

const int LIGHT = 33;
const int BLUE = 14;
const int GREEN = 27;
const int YELLOW = 12;
const int RED = 26;

void setup() {
    Serial.begin(115200);

    pinMode(BLUE, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(YELLOW, OUTPUT);
    pinMode(RED, OUTPUT);
}

void loop() {
    int value = analogRead(LIGHT);

    // Avval hamma LEDni o'chiramiz
    digitalWrite(BLUE, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(YELLOW, LOW);
    digitalWrite(RED, LOW);

    if (value >= 0 && value <= 1023) {
        digitalWrite(BLUE, HIGH);
        Serial.println("band=BLUE");
    }
    else if (value <= 2047) {
        digitalWrite(GREEN, HIGH);
        Serial.println("band=GREEN");
    }
    else if (value <= 3071) {
        digitalWrite(YELLOW, HIGH);
        Serial.println("band=YELLOW");
    }
    else {
        digitalWrite(RED, HIGH);
        Serial.println("band=RED");
    }

    delay(500);
}