 #include <Servo.h>
 
 Servo myservo;
 
 int pos = 0;
 int i = 0;
 
 void setup()
 {
   Serial.begin(9600);
   myservo.attach(9);
 }
 
 void loop()
 {
   for( i=0; i<180; i++ ) {
     myservo.write(i);
     Serial.println(i);
     delay(5);
   }
   delay(1000);
   for( i=180; i > 0; i--) {
     myservo.write(i);
     Serial.println(i);
     delay(5);
   }
 }
