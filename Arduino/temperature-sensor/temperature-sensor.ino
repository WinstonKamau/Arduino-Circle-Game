const int temp_pin=A0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float voltage;
  voltage = analogRead(temp_pin) * 5.0 / 1024;
  Serial.print("Voltage: ");
  Serial.print(voltage);

  float temp_c;
  temp_c = voltage * 1000.0 / 10.0;
  Serial.print("   Temperature: ");
  Serial.println(temp_c);
}

// Crispus put both sensors in his mouth!!! as per the video instructions
