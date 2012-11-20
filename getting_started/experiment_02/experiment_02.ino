const int LED    = 9; //Set LED output to pin 9
const int BUTTON = 7;

int i   = 0;
int val = 0;
int on  = 0;
int old = 0;

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}


void loop()
{
  val = digitalRead(BUTTON);

  if( val == HIGH && old == LOW ) {
    on = on - 1;
    delay(10);
  }
  
  old = val;
  
  if( on == 1 ) {
    for( i = 0; i < 255; i++ ) {
      analogWrite(LED, i);
      delay(10);
    }

  
    for( i = 255; i > 0; i-- ) {
      analogWrite(LED, i);
      delay(10);
    }
  }
  
}
