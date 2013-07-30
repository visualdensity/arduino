#include <RCSwitch.h>

int ledPin = 7;
boolean ledState = false;

RCSwitch receiver = RCSwitch();

void setup() {
  Serial.begin(9600);
  pinMode( ledPin, OUTPUT );
  receiver.enableReceive(0);  // Receiver on inerrupt 0 => that is pin #2
}

void loop() {
  if (receiver.available()) {
    
    int value = receiver.getReceivedValue();
    
    if (value == 0) {
      Serial.print("Unknown encoding");
    } else {
      int received = receiver.getReceivedValue();
      
      if( received == 5393 && ledState == false) {
        digitalWrite( ledPin, HIGH );
        ledState = true;
      } else {
        digitalWrite( ledPin, LOW );
        ledState = false;
      }
      
      Serial.print("Received: ");
      Serial.println( received );
    }

    receiver.resetAvailable();
  }
}
