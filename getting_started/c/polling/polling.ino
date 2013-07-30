#include <SimpleTimer.h>

SimpleTimer timer;
boolean currentLEDState;
int ledPin = 7;

void setup() 
{
  currentLEDState = false;
  pinMode(ledPin, OUTPUT);
  timer.setInterval(1000, blink);
}

void loop()
{
  timer.run();
}

void blink()
{
  if (!currentLEDState) {
    digitalWrite(ledPin, HIGH);
    currentLEDState = true;
  } else {
    digitalWrite(ledPin, LOW);
        currentLEDState = false;
  }
}
