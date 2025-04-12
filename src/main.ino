#include "Wire.h" 
#include "Ultrasonic.h"

const int LED_PIN = 3;
const int TRIGGER_PIN = 12;
const int ECHO_PIN = 13;

HC_SR04 sensor1(TRIGGER_PIN, ECHO_PIN);
int distance = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);      
}

void loop() {
  distance = sensor1.distance();
  
  Serial.print(distance / 100.0);
  Serial.println(" m");
  
  if (distance <= 30)
    digitalWrite(LED_PIN, HIGH);
  else
    digitalWrite(LED_PIN, LOW);
}
