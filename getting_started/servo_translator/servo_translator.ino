 #include <Servo.h>
 
 Servo myservo;
 
 const int POT = 4;
 
 int pos   = 0;
 int input = 0;
 
 void setup()
 {
   Serial.begin(9600);
   myservo.attach(9);
 }
 
 void loop()
 {
   input = analogRead(POT);
   Serial.println(input);
   
   pos = map(input, 1,350,1,180);
   myservo.write(pos);
 }
