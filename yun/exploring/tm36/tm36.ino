#include <Process.h>

int sensorPin = A0;

void setup() {
  Bridge.begin();	// Initialize the Bridge
  Serial.begin( 9600 );
  
  while(!Serial);
}

void loop() {

  Process p;

 //getting the voltage reading from the temperature sensor
 int reading = analogRead(sensorPin);  
 
 // converting that reading to voltage, for 3.3v arduino use 3.3
 float voltage = reading * 5.0;
 voltage /= 1024.0; 
 
 // print out the voltage
 Serial.print(voltage); Serial.println(" volts");
 
 // now print out the temperature
 float temperatureC = ((voltage - 0.5) * 100) - 9;
 Serial.print(temperatureC); Serial.println(" C");
 
  p.runShellCommand("/root/xwrite.sh test-channel " + String(temperatureC));
  while(p.running());  
   
   delay(60000);
}
