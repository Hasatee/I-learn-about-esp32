#include <Arduino.h>
#include <Servo.h>

#define VRX_PIN      36 // ESP32 pin GPIO36 (ADC0) connected to VRX pin
#define VRY_PIN      39 // ESP32 pin GPIO39 (ADC0) connected to VRY pin
#define SERVO_X_PIN  13 // ESP32 pin GPIO13 connected to Servo motor 1
#define SERVO_Y_PIN  25 // ESP32 pin GPIO25 connected to Servo motor 2

Servo xServo;  // create servo object to control a servo 1
Servo yServo;  // create servo object to control a servo 2

void setup() {
  Serial.begin(9600);

  // Set the ADC attenuation to 11 dB (up to ~3.3V input)
  analogSetAttenuation(ADC_11db);
  xServo.attach(SERVO_X_PIN);
  yServo.attach(SERVO_Y_PIN);
}

void loop() {
  // read X and Y analog values
  int valueX = analogRead(VRX_PIN);
  int valueY = analogRead(VRY_PIN);

  int xAngle = map(valueX, 0, 4095, 0, 180); // scale it to the servo's angle (0 to 180)
  int yAngle = map(valueY, 0, 4095, 0, 180); // scale it to the servo's angle (0 to 180)

  xServo.write(xAngle); // rotate servo motor 1
  yServo.write(yAngle); // rotate servo motor 2

  // print data to Serial Monitor on Arduino IDE
  Serial.print("Joystick: ");
  Serial.print(valueX);
  Serial.print(", ");
  Serial.print(valueY);
  Serial.print(" => Servo Motor: ");
  Serial.print(xAngle);
  Serial.print("°, ");
  Serial.print(yAngle);
  Serial.println("°");
  delay(500); // wait for a while
}