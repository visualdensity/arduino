 #include <Servo.h>
 
 Servo myservo;
 Servo myservo2;
 
 const int POT = 4;
 
 int pos1  = 0;
 int pos2  = 0;
 int input = 0;
 
 void setup()
 {
   Serial.begin(9600);
   myservo.attach(9);
   myservo2.attach(12);
 }
 
 void loop()
 {
   input = analogRead(POT);
   Serial.println(input);
   
   pos1 = map(input, 1,350,1,180);
   pos2 = map(input, 1,350,1,180);

   myservo.write(pos1);
   myservo2.write(pos2);

 }
