// create output pins
int led_1_red = 2;
int led_1_green = 3;
int led_2_red = 4;
int led_2_green = 5;
int led_3_red = 6;
int led_3_green = 7;
int led_3_blue = 8;
int but_red = 9;
int but_green = 10;
int but_blue = 11;
int btn_state_red = HIGH;
int btn_state_green = HIGH;
int btn_state_blue = HIGH;
int btn_prev_red = HIGH;
int btn_prev_green = HIGH;
int btn_prev_blue = HIGH;
unsigned long last_debounce_time = 0;
const int debounce_delay = 50;
bool sequence_count = false;
const int SEQ_LENGTH = 3;
int sequence_inputs[SEQ_LENGTH];
int seq_counter = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led_1_red, OUTPUT);
  pinMode(led_1_green, OUTPUT);
  pinMode(led_2_red, OUTPUT);
  pinMode(led_2_green, OUTPUT);
  pinMode(led_3_red, OUTPUT);
  pinMode(led_3_blue, OUTPUT);
  pinMode(but_red, INPUT_PULLUP);
  pinMode(but_green, INPUT_PULLUP);
  pinMode(but_blue, INPUT_PULLUP);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
sequence_1();
Serial.println(sequence_inputs[0]);
Serial.println(sequence_inputs[1]);
Serial.println(sequence_inputs[2]);
//Serial.println(sequence_inputs[3]);
Serial.println(SEQ_LENGTH);
while ( sequence_count == false ){
//  verify_input(sequence_inputs);
read_button();
 if(seq_counter == SEQ_LENGTH){
    success();
    seq_counter = 0;
    break;
  }
}

}

void verify_input(int* sequence, int btn_input){
  if(seq_counter < SEQ_LENGTH){
    if(sequence[seq_counter] == btn_input){
      success_2();
      seq_counter++;
    } else {
      fail();
      seq_counter = 0;
      sequence_count = true;
    }
  } else {
    fail();
    seq_counter = 0;
    sequence_count = true;
  }
}


void read_button() {
  int btn_read_red= digitalRead(but_red);
    if ( btn_read_red != btn_prev_red ) {
    last_debounce_time = millis();
    }

     if ( millis() > (last_debounce_time + debounce_delay) ) {
    if ( btn_read_red != btn_state_red ) {
      btn_state_red = btn_read_red;
      if ( btn_state_red == LOW ) {
        setColor("led2", 0, 0 ,0 );
        setColor("led3", 0, 0 ,0 );
        setColor("led1", 255, 0 ,0 );
        delay(500);
        setColor("led1", 0, 0 ,0 );
        verify_input(sequence_inputs, 1);
        }
      }
    }
   btn_prev_red = btn_read_red;

  int btn_read_green= digitalRead(but_green);
    if ( btn_read_green != btn_prev_green ) {
    last_debounce_time = millis();
    }

     if ( millis() > (last_debounce_time + debounce_delay) ) {
    if ( btn_read_green != btn_state_green ) {
      btn_state_green = btn_read_green;
      if ( btn_state_green == LOW ) {
        setColor("led1", 0, 0 ,0 );
        setColor("led3", 0, 0 ,0 );
        setColor("led2", 0, 255 ,0 );
        delay(500);
        setColor("led2", 0, 0 ,0 );
        verify_input(sequence_inputs, 2);
        }
      }
    }
   btn_prev_green = btn_read_green;

     int btn_read_blue= digitalRead(but_blue);
    if ( btn_read_blue != btn_prev_blue ) {
    last_debounce_time = millis();
    }

     if ( millis() > (last_debounce_time + debounce_delay) ) {
    if ( btn_read_blue != btn_state_blue ) {
      btn_state_blue = btn_read_blue;
      if ( btn_state_blue == LOW ) {
        setColor("led2", 0, 0 ,0 );
        setColor("led1", 0, 0 ,0 );
        setColor("led3", 0, 0 ,255 );
        delay(500);
        setColor("led3", 0, 0 ,0 );
        verify_input(sequence_inputs, 3);
        }
      }
    }
   btn_prev_blue = btn_read_blue;
  
  }



void sequence_1() {
  setColor("led3", 0, 0 ,255 );
  sequence_inputs[0] = 3;
  delay(1000);
  setColor("led3", 0, 0 ,0 );
  setColor("led2", 0, 255 ,0 );
  sequence_inputs[1] = 2;
  delay(1000);
  setColor("led2", 0, 0 ,0 );
  setColor("led1", 255, 0 ,0 );
  sequence_inputs[2] = 1;
  delay(1000);
  setColor("led1", 0, 0 ,0 );
  sequence_count = false;
  }
void sequence_2() {
   setColor("led3", 0, 0 ,255 );
   sequence_inputs[0] = 3; 
  delay(1000);
  setColor("led3", 0, 0 ,0 ); 
  setColor("led1", 255, 0 ,0 );
  sequence_inputs[1] = 1; 
  delay(1000);
  setColor("led1", 0, 0 ,0 );
  setColor("led3", 0, 0 ,255 ); 
  sequence_inputs[2] = 3; 
  delay(1000);
  setColor("led3", 0, 0 ,0 );
  setColor("led2", 0, 255 ,0 );
  sequence_inputs[3] = 2; 
  delay(1000);
  setColor("led2", 0, 0 ,0 );
  sequence_count = false;
  }

void sequence_3() {
  setColor("led2", 0, 255 ,0 );
  delay(1000);
  setColor("led2", 0, 0 ,0 );
  setColor("led1", 255, 0 ,0 );
  delay(1000);
  setColor("led1", 0, 0 ,0 );
  setColor("led3", 0, 0 ,255 ); 
  delay(1000);
  setColor("led3", 0, 0 ,0 );
  setColor("led2", 0, 255 ,0 );
  delay(1000);
  setColor("led2", 0, 0 ,0 );
  setColor("led3", 0, 0 ,255 ); 
  delay(1000);
  setColor("led3", 0, 0 ,0 ); 
  }

void fail() {
setColor("led1", 255, 0, 0);
setColor("led2", 255, 0, 0);
setColor("led3", 255, 0, 0);
delay(500);
setColor("led1", 0, 0, 0);
setColor("led2", 0, 0, 0);
setColor("led3", 0, 0, 0);
delay(500);
}

void success() {
setColor("led1", 0, 255, 0);
setColor("led2", 0, 255, 0);
setColor("led3", 0, 255, 0);
delay(500);
setColor("led1", 0, 0, 0);
setColor("led2", 0, 0, 0);
setColor("led3", 0, 0, 0);
delay(500);
}

void success_2() {
  setColor("led1", 0, 255, 0);
  setColor("led2", 0, 255, 0);
  delay(500);
  setColor("led1", 0, 0, 0);
  setColor("led2", 0, 0, 0);
  }


void setColor(String pin, int red, int green, int blue) {
if (pin == "led1"){
  analogWrite(led_1_red, red);
  analogWrite(led_1_green, green);
 }
if(pin =="led2"){
  analogWrite(led_2_red, red);
  analogWrite(led_2_green, green);
  }
if(pin =="led3"){
  analogWrite(led_3_red, red);
  analogWrite(led_3_green, green);
    analogWrite(led_3_blue, blue);
  }
  
  
}
