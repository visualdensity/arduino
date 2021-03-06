/*
 * Switch test program
 */

int switchPin = 7;              // Switch connected to digital pin 2

void setup()                    // run once, when the sketch starts
{
  Serial.begin(9600);           // set up Serial library at 9600 bps
  pinMode(switchPin, INPUT);    // sets the digital pin as input to read switch
}


void loop()                     // run over and over again
{
  Serial.print("Read switch input: ");
  Serial.println(digitalRead(switchPin));    // Read the pin and display the value
  delay(1000);
}
