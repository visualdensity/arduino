const int LED = 9; // LED sitting at digital output #9
int i=0;

void setup()
{
  pinMode(LED, OUTPUT);
}

void loop()
{
  for( i=0; i < 255; i++ ) {
    analogWrite(LED, i);
    delay(10);
  }
  
  for( i=255; i > 0; i-- ) {
    analogWrite(LED, i);
    delay(10);
  }
}
