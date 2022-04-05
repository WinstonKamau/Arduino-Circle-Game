const int x_pin =A0;
const int y_pin = A2;
const int z_pin = A4;

//Volts per G-force
const float sensitivity = 0.33;


void setup() {
  analogReference(EXTERNAL);
  Serial.begin(9600);

}

void loop() {
  float x;
  float y;
  float z;

  // Read pins and convert to G
  x = (analogRead(x_pin) - 512) * 3.3 /(sensitivity * 1023);
  y = (analogRead(y_pin) - 512) * 3.3 /(sensitivity * 1023);
  z = (analogRead(z_pin) - 512) * 3.3 /(sensitivity * 1023);

  Serial.print("x: ");
  Serial.print(x);
  Serial.print("y: ");
  Serial.print(y);
  Serial.print("z: ");
  Serial.println(z);

  delay(100);

}
