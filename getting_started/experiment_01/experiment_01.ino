const int RED    = 12;
const int GREEN  = 9;
const int BUTTON = 7; 

int val     = 0;
int timeout = 1000;
int old_val = 0;
int state   = 0;

void setup() {
  pinMode(RED,    OUTPUT);
  pinMode(GREEN,  OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {

  val = digitalRead(BUTTON);
  
  if( (val == HIGH) && (old_val == LOW) ) {
    state = 1;
  } else {
    state = 0;
  }
  
  old_val = val;
  
  if( state == 1 ) {
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
  } else {
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, HIGH);
  }
}
