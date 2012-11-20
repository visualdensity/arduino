const int LED    = 13; // set LED pin number
const int BUTTON = 7;  // set button pin number

int val   = 0; // store the state of input pin
int old   = 0; // store the previous val state
int state = 0; // 0 is off, 1 is on

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop()
{
  val = digitalRead(BUTTON);
  
  if( (val == HIGH) && (old == LOW) ) 
  {
    state = 1-state;
  }
  old = val;
  
  if( state == 1 )
  {
    digitalWrite(LED, HIGH);
  } else 
  {
    digitalWrite(LED, LOW);
  }
}
