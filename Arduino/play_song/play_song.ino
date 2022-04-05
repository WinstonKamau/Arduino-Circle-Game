const int speaker_pin = 9;

void setup() {
  // put your setup code here, to run once:
pinMode(speaker_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//tone(speaker_pin, 261.63, 500); // C
//delay(500);
//tone(speaker_pin, 293.66, 500); // D
//delay(500);
//tone(speaker_pin, 329.63, 500); // E
//delay(500);
//tone(speaker_pin, 349.23, 500); // F
//delay(500);
//tone(speaker_pin, 392.00, 500); // G
//delay(500);
//tone(speaker_pin, 440.00, 500); // A
//delay(500);
//tone(speaker_pin, 493.88, 500); // B
//delay(500);
//tone(speaker_pin, 523.25, 500); // C
twinkle_twinkle();
delay(1000);
}

void twinkle_twinkle(){
  // C C G G | A A G.. | F F E E | D D C..
  tone(speaker_pin, 261.63, 250); // C
  delay(500);
  tone(speaker_pin, 261.63, 250); // C
  delay(500);
  tone(speaker_pin, 392.00, 250); // G
  delay(500);
  tone(speaker_pin, 392.00, 250); // G
  delay(500);

  tone(speaker_pin, 440.00, 250); // A
  delay(500);
  tone(speaker_pin, 440.00, 250); // A
  delay(500);
  tone(speaker_pin, 392.00, 500); // G
  delay(500);
  delay(500);

  tone(speaker_pin, 349.23, 250); // F
  delay(500);
  tone(speaker_pin, 349.23, 250); // F
  delay(500);
  tone(speaker_pin, 329.63, 250); // E
  delay(500);
  tone(speaker_pin, 329.63, 250); // E
  delay(500);

  tone(speaker_pin, 293.66, 250); // D
  delay(500);
  tone(speaker_pin, 293.66, 250); // D
  delay(500);
  tone(speaker_pin, 261.63, 500); // C
  delay(500);
  delay(250);
}
