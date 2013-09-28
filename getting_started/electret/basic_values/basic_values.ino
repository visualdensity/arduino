#include <Process.h>

int high = 0;

// the setup routine runs once when you press reset:
void setup() {
  // Initialize Bridge
  Bridge.begin();
  
  Serial.begin(9600);  // initialize serial communication
  while(!Serial);      // do nothing until the serial monitor is opened

  Serial.println("Connection established...");
  
  pinMode( 8, OUTPUT );
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);

  if( sensorValue > 575 ) {
      digitalWrite( 8, HIGH );
  } else {
      digitalWrite( 8, LOW );
  }

  Serial.println("SensorValue: " + String(sensorValue));
  delay(50);
}
