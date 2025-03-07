#include <Arduino.h>
#include <Servo.h>

#define POTENTIOMETER_PIN  36  // ESP32 pin GPIO36 (ADC0) connected to Potentiometer pin
#define SERVO_PIN          26  // ESP32 pin GPIO26 connected to Servo Motor's pin
#define VOLTAGE_THRESHOLD  2.5 // Voltages

Servo servo; // create servo object to control a servo

float floatMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void setup() {
  // set the ADC attenuation to 11 dB (up to ~3.3V input)
  analogSetAttenuation(ADC_11db);
  servo.attach(SERVO_PIN);   // attaches the servo on pin 9 to the servo object
  servo.write(0);
}

void loop() {
  int analogValue = analogRead(POTENTIOMETER_PIN);      // read the input on analog pin
  float voltage = floatMap(analogValue, 0, 1023, 0, 5); // Rescale to potentiometer's voltage

  if (voltage > VOLTAGE_THRESHOLD)
    servo.write(90); // rotate servo motor to 90 degree
  else
    servo.write(0);  // rotate servo motor to 0 degree
}

