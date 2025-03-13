#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd_i2c(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows

void setup() {
  lcd_i2c.init(); // initialize the lcd
  lcd_i2c.backlight();
}

void loop() {
  lcd_i2c.clear();              // clear display
  lcd_i2c.setCursor(0, 0);      // move cursor to   (0, 0)
  lcd_i2c.print("Hello");       // print message at (0, 0)
  lcd_i2c.setCursor(2, 1);      // move cursor to   (2, 1)
  lcd_i2c.print("esp32io.com"); // print message at (2, 1)
  delay(2000);                  // display the above for two seconds

  lcd_i2c.clear();                  // clear display
  lcd_i2c.setCursor(3, 0);          // move cursor to   (3, 0)
  lcd_i2c.print("DIYables");        // print message at (3, 0)
  lcd_i2c.setCursor(0, 1);          // move cursor to   (0, 1)
  lcd_i2c.print("www.diyables.io"); // print message at (0, 1)
  delay(2000);                      // display the above for two seconds
}
