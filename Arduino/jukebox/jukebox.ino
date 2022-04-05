# include <LiquidCrystal.h>
#define C4 261.63
#define D4 293.66
#define E4 329.63
#define F4 349.23
#define G4 392.00
#define A4 440.00
#define B4 493.88
#define C5 523.25

const int speaker_pin = 10;

// Twinkle Twinkle Little Star
const int song_length_1 = 14;
double notes_1[] = {C4, C4, G4, G4, A4, A4, G4, F4, F4, E4, E4, D4, D4, C4};
int beats_1[] = {1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2};
int tempo_1 = 300;
// Isty bisty spider
double notes_2[] = {C4, C4, G4, G4, A4, A4, G4, F4, F4, E4, E4, D4, D4, C4};
int beats_2[] = {1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2};
int tempo_2 = 300;

const int left_btn_pin = 8;
const int right_btn_pin = 9;
int left_btn_prev = HIGH;
int right_btn_prev = HIGH;
unsigned long last_debounce_time = 0;
const int debounce_delay = 50;
int cursor_position = 0;
int left_btn_state = HIGH;
int right_btn_state = HIGH;
int song_counter = 0;
String song_name[2] = {"Twinkle Twinkle", "Itsy Bitsy"};
LiquidCrystal lcd(12, 11, 2, 3, 4, 5);

void setup() {
  pinMode(left_btn_pin, INPUT_PULLUP);
  pinMode(right_btn_pin, INPUT_PULLUP);
  pinMode(speaker_pin, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("Juke box");
  delay(1000);
  Serial.begin(9600);
}

void loop() {
  int left_btn_read = digitalRead(left_btn_pin);
  int right_btn_read = digitalRead(right_btn_pin);
  lcd.setCursor(0,0);
  
  lcd.print(song_name[song_counter]);
 
  if ( left_btn_read != left_btn_prev || right_btn_read != right_btn_prev ) {
    last_debounce_time = millis();
  }

  if ( millis() > (last_debounce_time + debounce_delay) ) {
    if ( left_btn_read != left_btn_state ) {
      left_btn_state = left_btn_read;
      if ( left_btn_state == LOW ) {
        if (song_counter == 0){
          song_counter = 1;
          }
         else{
          song_counter = 0;
          }
          lcd.clear();
      }
    }
    if ( right_btn_read != right_btn_state ) {
      right_btn_state = right_btn_read;
      if ( right_btn_state == LOW ) {
        if (song_counter == 0){
          playSong(notes_1, beats_1, tempo_1, song_length_1);
          Serial.println("000");
          }
          else {
          playSong(notes_1, beats_1, tempo_1, song_length_1);
          Serial.println("111");
            }
           
      }
    }
  }
  left_btn_prev = left_btn_read;
  right_btn_prev = right_btn_read;

}

void playSong(double notes[], int beats[], int tempo, int song_length){
  // Play each note
  for (int i = 0; i < song_length; i++) {
    int duration = beats[i] * tempo;
    if ( notes[i] == 0 ) {
      delay(duration);
    } else {
      tone(speaker_pin, notes[i], duration);
      delay(duration);
    }
  }
  delay(tempo / 10);
}
