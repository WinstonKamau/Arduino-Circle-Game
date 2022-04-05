# include <LiquidCrystal.h>
const int left_btn_pin = 8;
const int right_btn_pin = 9;
int left_btn_prev = HIGH;
int right_btn_prev = HIGH;
unsigned long last_debounce_time = 0;
const int debounce_delay = 50;
int cursor_position = 0;
int left_btn_state = HIGH;
int right_btn_state = HIGH;


LiquidCrystal lcd(12, 11, 2, 3, 4, 5);

byte sword[8] = {
  B00100,
  B01110,
  B01010,
  B01010,
  B01010,
  B11111,
  B00100,
  B00100,
};

void setup() {
  pinMode(left_btn_pin, INPUT_PULLUP);
  pinMode(right_btn_pin, INPUT_PULLUP);
  lcd.createChar(0, sword);
  lcd.begin(16, 2);
}

void loop() {
  lcd.setCursor(cursor_position, 1);
  

  int left_btn_read = digitalRead(left_btn_pin);
  int right_btn_read = digitalRead(right_btn_pin);
 
 
  if ( left_btn_read != left_btn_prev || right_btn_read != right_btn_prev ) {
    last_debounce_time = millis();
  }

  if ( millis() > (last_debounce_time + debounce_delay) ) {
    if ( left_btn_read != left_btn_state ) {
      left_btn_state = left_btn_read;
      if ( left_btn_state == LOW ) {
        // move the sprite left
        cursor_position--;
        if(cursor_position < 0){
          cursor_position = 15;
        }
        lcd.clear();
        lcd.setCursor(cursor_position, 1);
      }
    }
    if ( right_btn_read != right_btn_state ) {
      right_btn_state = right_btn_read;
      if ( right_btn_state == LOW ) {
        // move the sprite right
        cursor_position++;
        if(cursor_position > 15){
          cursor_position = 0;
        }
        lcd.clear();
        lcd.setCursor(cursor_position, 1);
      }
    }
  }
  left_btn_prev = left_btn_read;
  right_btn_prev = right_btn_read;
  lcd.write(byte(0));
}
