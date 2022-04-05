const int btn_pin = 2;
const int led_pin = 6;
bool state = false;
int btn_prev = HIGH;

void setup() {
  pinMode(btn_pin, INPUT);
  pinMode(led_pin, OUTPUT);
  }

void loop() {
  int btn_state;

  btn_state = digitalRead(btn_pin);
  
  if ( (btn_state == LOW) && (btn_prev ==HIGH) ) {
    if ( state == false ) {
      state=true;
      digitalWrite(led_pin, HIGH);
      }
     else {
      state =false;
      digitalWrite(led_pin, LOW);
      }
    } 

    btn_prev = btn_state;

  }
