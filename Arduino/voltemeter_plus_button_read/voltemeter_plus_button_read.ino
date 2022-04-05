const int btn_pin = 2;
const int debounce_delay = 50;
const int ain_pin = A0;
int btn_state = HIGH;
int btn_prev = HIGH;
unsigned long last_debounce_time = 0;


void setup() {
  pinMode(btn_pin, INPUT_PULLUP);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int btn_read = digitalRead(btn_pin);

  if ( btn_read != btn_prev ) {
    last_debounce_time = millis();
    }

  if ( millis() > (last_debounce_time + debounce_delay) ) {
    if ( btn_read != btn_state ) {
      btn_state = btn_read;
      if ( btn_state == LOW ) {
        Serial.println("Pressed");
        int val = analogRead(ain_pin);
        float voltage = val * 5.0 / 1023;
        Serial.println(voltage);
        }
      }
    }
   btn_prev = btn_read;

}
