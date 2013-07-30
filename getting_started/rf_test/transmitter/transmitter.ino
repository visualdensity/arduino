/**
 * 433 MHz Transmitter
 */

#include <RCSwitch.h>

int transmitPin = 8;
int buttonPin  = 7;

RCSwitch transmitter = RCSwitch();

void setup() 
{
  pinMode(buttonPin, INPUT);
  transmitter.enableTransmit(transmitPin);

}

void loop()
{
  
  int button = digitalRead(buttonPin);
  
  if( button == HIGH ) {
      transmitter.send(5393, 24);
  } else {
      transmitter.send(5393, 24);
  }
  delay(150);
}
