#include <Arduino.h>
 #include "pitches.h"

 #define BUTTON_PIN 16 // ESP32 GPIO16 pin connected to button's pin
 #define BUZZER_PIN 21 // ESP32 GPIO21 pin connected to Buzzer's pin
 
 // notes in the melody:
 int melody[] = {
   NOTE_E5, NOTE_E5, NOTE_E5,
   NOTE_E5, NOTE_E5, NOTE_E5,
   NOTE_E5, NOTE_G5, NOTE_C5, NOTE_D5,
   NOTE_E5,
   NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5,
   NOTE_F5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,
   NOTE_E5, NOTE_D5, NOTE_D5, NOTE_E5,
   NOTE_D5, NOTE_G5
 };
 
 // note durations: 4 = quarter note, 8 = eighth note, etc, also called tempo:
 int noteDurations[] = {
   8, 8, 4,
   8, 8, 4,
   8, 8, 8, 8,
   2,
   8, 8, 8, 8,
   8, 8, 8, 16, 16,
   8, 8, 8, 8,
   4, 4
 };
 
 void buzzer() {
   // iterate over the notes of the melody:
   int size = sizeof(noteDurations) / sizeof(int);
 
   for (int thisNote = 0; thisNote < size; thisNote++) {
     // to calculate the note duration, take one second divided by the note type.
     //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
     int noteDuration = 1000 / noteDurations[thisNote];
     tone(BUZZER_PIN, melody[thisNote], noteDuration);
 
     // to distinguish the notes, set a minimum time between them.
     // the note's duration + 30% seems to work well:
     int pauseBetweenNotes = noteDuration * 1.30;
     delay(pauseBetweenNotes);
     // stop the tone playing:
     noTone(BUZZER_PIN);
   }
 }

 void setup() {
   Serial.begin(9600);                // initialize serial
   pinMode(BUTTON_PIN, INPUT_PULLUP); // set ESP32 pin to input pull-up mode
 }
 
 void loop() {
   int buttonState = digitalRead(BUTTON_PIN); // read new state
 
   if (buttonState == LOW) { // button is pressed
     Serial.println("The button is being pressed");
     buzzer();
   }
 }
 