const int knob_pin = A0;
const int led_pin = 5;

void setup() {
  pinMode(led_pin, OUTPUT);
}

void loop() {
  // read knob value (0-1023)
  int val = analogRead(knob_pin);

  // convert knob value to PWM value (0-255)
  int brightness = map(val, 0, 1023, 0, 255);
  
  analogWrite(led_pin, brightness);
}
