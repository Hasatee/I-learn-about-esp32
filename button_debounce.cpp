#include <Arduino.h>
#include <ezButton.h>

#define DEBOUNCE_TIME 50 // the debounce time in millisecond, increase this time if it still chatters

ezButton button1(21); // create ezButton object that attach to pin GPIO21;
ezButton button2(22); // create ezButton object that attach to pin GPIO22;
ezButton button3(23); // create ezButton object that attach to pin GPIO23;

void setup() {
  Serial.begin(9600);
  button1.setDebounceTime(DEBOUNCE_TIME); // set debounce time to 50 milliseconds
  button2.setDebounceTime(DEBOUNCE_TIME); // set debounce time to 50 milliseconds
  button3.setDebounceTime(DEBOUNCE_TIME); // set debounce time to 50 milliseconds
}

void loop() {
  button1.loop(); // MUST call the loop() function first
  button2.loop(); // MUST call the loop() function first
  button3.loop(); // MUST call the loop() function first

  if (button1.isPressed())
    Serial.println("The button 1 is pressed");

  if (button1.isReleased())
    Serial.println("The button 1 is released");

  if (button2.isPressed())
    Serial.println("The button 2 is pressed");

  if (button2.isReleased())
    Serial.println("The button 2 is released");

  if (button3.isPressed())
    Serial.println("The button 3 is pressed");

  if (button3.isReleased())
    Serial.println("The button 3 is released");
}