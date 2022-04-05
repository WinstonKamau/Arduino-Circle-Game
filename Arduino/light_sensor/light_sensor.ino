const int light_pin = A0;
const int led_pin_2 = 2;
const int led_pin_3 = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led_pin_2, OUTPUT);
  pinMode(led_pin_3, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int light_val = analogRead(light_pin);
if (light_val <= 250){
    digitalWrite(led_pin_2, HIGH);
    digitalWrite(led_pin_3, HIGH);

  }
else {
      digitalWrite(led_pin_2, LOW);
    digitalWrite(led_pin_3, LOW);
  }
 
}
