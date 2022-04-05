const int speaker_pin = 9;

void setup() {
  // put your setup code here, to run once:
pinMode(speaker_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
tone(speaker_pin, 523.25, 500);
delay(500);
tone(speaker_pin, 587.33, 500);
delay(500);
tone(speaker_pin, 659.25, 500);
delay(500);
tone(speaker_pin, 698.46, 500);
delay(500);
tone(speaker_pin, 783.99, 500);
delay(500);
tone(speaker_pin, 880.00, 500);
delay(500);
tone(speaker_pin, 987.77, 500);
delay(500);
tone(speaker_pin, 1046.50, 500);
delay(1000);
}
