//The Switch -- again

int inputPin = 7;
int ledPin   = 3;
int switchState = 0;
int inByte = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(inputPin, INPUT);
  pinMode(ledPin, OUTPUT);
  handShake();
}

void loop()
{
  
  if( Serial.available() > 0 ) {
      inByte = Serial.read();
      switchState = digitalRead(inputPin);
  
      if( switchState == 0 ) {
        digitalWrite(ledPin, LOW);
        Serial.write(0);
        Serial.write(0);
      } else {
        digitalWrite(ledPin, HIGH);
        Serial.write(0);
        Serial.write(1);
      } 

  }
  
  delay(150);
}

void handShake()
{
  while( Serial.available() <= 0)
  {
    Serial.print('Z');
    delay(200);
  }
}
