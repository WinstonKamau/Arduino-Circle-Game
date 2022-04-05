const int trig_pin = 9;
const int echo_pin = 10;

long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
pinMode(trig_pin, OUTPUT);
pinMode(echo_pin, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);

  duration = pulseIn(echo_pin, HIGH);
  distance = duration *0.034/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);

}
