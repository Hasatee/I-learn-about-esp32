#include <Arduino.h>

/*
#define AO_PIN 36  // ESP32's pin GPIO36 connected to AO pin of the MQ2 sensor

void setup() {
  // initialize serial communication
  Serial.begin(9600);

  // set the ADC attenuation to 11 dB (up to ~3.3V input)
  analogSetAttenuation(ADC_11db);
  Serial.println("Warming up the MQ2 sensor");
  delay(20000);  // wait for the MQ2 to warm up
}

void loop() {
  int gasValue = analogRead(AO_PIN);

  Serial.print("MQ2 sensor AO value: ");
  Serial.println(gasValue);
}
*/
#define DO_PIN 16  // ESP32's pin GPIO16 connected to DO pin of the MQ2 sensor

void setup() {
  // initialize serial communication
  Serial.begin(9600);
  // initialize the ESP32's pin as an input
  pinMode(DO_PIN, INPUT);

  Serial.println("Warming up the MQ2 sensor");
  delay(20000);  // wait for the MQ2 to warm up
}

void loop() {
  int gasState = digitalRead(DO_PIN);

  if (gasState == HIGH)
    Serial.println("The gas is NOT present");
  else
    Serial.println("The gas is present");
}