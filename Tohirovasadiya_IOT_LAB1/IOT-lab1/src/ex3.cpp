#include <Arduino.h>

const int LIGHT_PIN = 33;      
const long INTERVAL = 500;    

unsigned long previousMillis = 0;  

void setup() {
  Serial.begin(115200);       
  pinMode(LIGHT_PIN, INPUT);   
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= INTERVAL) {
    previousMillis = currentMillis;

    int raw = analogRead(LIGHT_PIN);  

    Serial.print("raw=");
    Serial.println(raw);
  }
}
