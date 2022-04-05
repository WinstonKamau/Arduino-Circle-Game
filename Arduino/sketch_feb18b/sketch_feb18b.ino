const int btn_pin = 2;

int btn_prev;
int counter;

void setup() {
  // Configure pins
  Serial.begin(9600);
  pinMode(btn_pin, INPUT_PULLUP);
  counter = 0;

}

void loop() {
  int btn_state;
  btn_state = digitalRead(btn_pin);

  if ( (btn_prev == LOW) && (btn_state == HIGH) ) {
   Serial.println(counter);
   counter += 1;
    }

   btn_prev = btn_state;

}
