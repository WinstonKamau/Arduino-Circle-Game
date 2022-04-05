const int btn_pin = 2;
const int led_pin = 6;

int btn_prev;

void setup() {
  // Configure pins
  pinMode(btn_pin, INPUT_PULLUP);
  pinMode(led_pin, OUTPUT);

  digitalWrite(led_pin, LOW);

}

void loop() {
  int btn_state;
  btn_state = digitalRead(btn_pin);

  if ( (btn_prev == LOW) && (btn_state == HIGH) ) {
    digitalWrite(led_pin, HIGH);
    delay(500);
    digitalWrite(led_pin, LOW);
    }

   btn_prev = btn_state;

}
