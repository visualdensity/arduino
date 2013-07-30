#include <SimpleTimer.h>

boolean myBool;
char myChar;
int myInt;
float myFloat;
String myString;

void setup()
{
  Serial.begin(9600);
  myBool = false;
  myChar = 'A';
  myInt = 1;
  myFloat = 5.682;
  myString = "Hello there cruel world";
}

void loop() 
{
  Serial.println( myString); 
  Serial.println(myString.length());
  Serial.println( myString + "!");
  delay(2000);
}
