#include <Arduino.h>
#include <ezLED.h> // ezLED library

#define PIN_LED_1 16 // The ESP32 pin GPIO16 connected to LED 1
#define PIN_LED_2 17 // The ESP32 pin GPIO17 connected to LED 2
#define PIN_LED_3 18 // The ESP32 pin GPIO18 connected to LED 3

ezLED led1(PIN_LED_1);  // create ezLED object that attach to pin PIN_LED_1
ezLED led2(PIN_LED_2);  // create ezLED object that attach to pin PIN_LED_2
ezLED led3(PIN_LED_3);  // create ezLED object that attach to pin PIN_LED_3

void setup() {
  Serial.begin(9600);

  led1.blink(500, 500); // 500ms ON, 500ms OFF, blink immediately
  led2.blink(200, 800); // 200ms ON, 800ms OFF, blink immediately
  led3.blink(200, 200); // 200ms ON, 200ms OFF, blink immediately
}

void loop() {
  led1.loop(); // MUST call the led1.loop() function in loop()
  led2.loop(); // MUST call the led2.loop() function in loop()
  led3.loop(); // MUST call the led3.loop() function in loop()

  // DO SOMETHING HERE
}
