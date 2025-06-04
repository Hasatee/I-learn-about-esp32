#include <Arduino.h>

#define ANALOG_PIN 34
#define DIGITAL_PIN 15

void setup() {
    pinMode(DIGITAL_PIN, INPUT_PULLUP);
    Serial.begin(115200);
    Serial.println("KY-038 Sound Sensor Test");
}

void loop() {
    int raw_value = analogRead(ANALOG_PIN);
    float voltage = raw_value * (3.3 / 4095.0) * 1000; // Convert to millivolts
    int digital_value = digitalRead(DIGITAL_PIN);
    Serial.printf("Analog Voltage: %.2f mV, Digital State: %s\n", voltage, digital_value ? "Sound Detected" : "No Sound");
    delay(1000);
}
