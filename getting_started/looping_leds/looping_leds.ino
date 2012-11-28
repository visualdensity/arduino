//Looping through an array of LED

int timer     = 30;
int pause     = 400;
int ledPins[] = { 2,3,4,5, };
int pinCount  = 4;

void setup()
{
  for ( int i = 0; i < pinCount; i++ ) 
  {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop()
{
  for( int i=0; i < pinCount; i++ ) 
  {
    digitalWrite(ledPins[i], HIGH);
    delay(timer);
    digitalWrite(ledPins[i], LOW);
  }
  
  for( int i= pinCount-1; i >= 0; i-- ) 
  {
    digitalWrite(ledPins[i], HIGH);
    delay(timer);
    digitalWrite(ledPins[i], LOW);
  }
  
  delay(pause);
}
