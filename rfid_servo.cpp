#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define SS_PIN    5  // ESP32 pin GPIO5 
#define RST_PIN   27 // ESP32 pin GPIO27 
#define SERVO_PIN 32 // ESP32 pin GPIO32 connects to servo motor

// SCK pin = GPIO18;
// MISO pin = GPIO19;
// MOSI pin = GPIO23;
// SS pin = GPIO5;
// RST pin = GPIO27;

MFRC522 rfid(SS_PIN, RST_PIN);
Servo servo;

byte authorizedUID[4] = {0x03, 0x11, 0x89, 0x13};
int angle = 0; // the current angle of servo motor

void setup() {
  Serial.begin(9600);
  SPI.begin(); // init SPI bus
  rfid.PCD_Init(); // init MFRC522
  servo.attach(SERVO_PIN);
  servo.write(angle); // rotate servo motor to 0°

  Serial.println("Tap RFID/NFC Tag on reader");
}

void loop() {
  if (rfid.PICC_IsNewCardPresent()) { // new tag is available
    if (rfid.PICC_ReadCardSerial()) { // NUID has been readed
      MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);

      if (rfid.uid.uidByte[0] == authorizedUID[0] &&
          rfid.uid.uidByte[1] == authorizedUID[1] &&
          rfid.uid.uidByte[2] == authorizedUID[2] &&
          rfid.uid.uidByte[3] == authorizedUID[3] ) {
        Serial.println("Authorized Tag");

        // change angle of servo motor
        if (angle == 0)
          angle = 90;
        else //if(angle == 90)
          angle = 0;

        // control servo motor arccoding to the angle
        servo.write(angle);
        Serial.print("Rotate Servo Motor to ");
        Serial.print(angle);
        Serial.println("°");
      } else {
        Serial.print("Unauthorized Tag with UID:");
        for (int i = 0; i < rfid.uid.size; i++) {
          Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
          Serial.print(rfid.uid.uidByte[i], HEX);
        }
        Serial.println();
      }

      rfid.PICC_HaltA(); // halt PICC
      rfid.PCD_StopCrypto1(); // stop encryption on PCD
    }
  }
}
