#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 2, 3, 4, 5); // (RegisterSelect, Enable, ...Data Pins)


void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2); // (# of xters per row, # of rows)
  lcd.clear();
  lcd.print("hello, world!");
}

void loop() {
  // put your main code here, to run repeatedly:
  int counter = millis() / 1000;
  lcd.setCursor(0, 1); // (xter position x-axis, row number)
  lcd.print(counter);
  lcd.setCursor(7, 1); // (xter position x-axis, row number)
  lcd.print(counter);
}
