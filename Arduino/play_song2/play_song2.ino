const int speaker_pin = 9;
 
// Twinkle Twinkle Little Star
const int song_length = 14;
int song_freqs[] = {262, 262, 392, 392, 440, 440, 392, 
                      349, 349, 329, 329, 294, 294, 262};
int song_beats[] = {1,   1,   1,   1,   1,   1,   2,
                      1,   1,   1,   1,   1,   1,   2};
int song_tempo = 300;
 
void setup() {
  pinMode(speaker_pin, OUTPUT);
}
 
void loop() {
  
  // Play each note
  for (int i = 0; i < song_length; i++) {
    int duration = song_beats[i] * song_tempo;
    if ( song_freqs[i] == 0 ) {
      delay(duration);
    } else {
      tone(speaker_pin, song_freqs[i], duration);
      delay(duration);
    }
  }
  delay(song_tempo / 10);
  
  delay(1000);
}
