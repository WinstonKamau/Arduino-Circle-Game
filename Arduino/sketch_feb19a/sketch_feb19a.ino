const int increment_btn_pin = 2;
const int decrement_btn_pin = 6;
unsigned long last_debounce_time = 0;
const int debounce_delay = 50;
int counter = 0;
int increment_btn_state = HIGH;
int decrement_btn_state = HIGH;
int increment_btn_prev = HIGH;
int decrement_btn_prev = HIGH;
void setup() {
  // put your setup code here, to run once:
  pinMode(increment_btn_pin, INPUT_PULLUP);
  pinMode(decrement_btn_pin, INPUT_PULLUP);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  int increment_btn_read = digitalRead(increment_btn_pin);
  int decrement_btn_read = digitalRead(decrement_btn_pin);

  if ( increment_btn_read != increment_btn_prev || decrement_btn_read != decrement_btn_prev ) {
    last_debounce_time = millis();
    }

  if ( millis() > (last_debounce_time + debounce_delay) ) {
    if ( increment_btn_read != increment_btn_state ) {
      increment_btn_state = increment_btn_read;
      if ( increment_btn_state == LOW ) {
        counter ++;
        Serial.println(counter);
        }
      }
    if ( decrement_btn_read != decrement_btn_state ) {
      decrement_btn_state = decrement_btn_read;
      if ( decrement_btn_state == LOW ) {
        counter --;
        Serial.println(counter);
        }
      }
    }
   increment_btn_prev = increment_btn_read;
   decrement_btn_prev = decrement_btn_read;

}
