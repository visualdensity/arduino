/*
Make Projects: How to Drive a 7 Segment LED
 URL: http://makeprojects.com/Project/Drive+a+7-Segment+LED+with+an+Arduino/645/1?singlePage#.ULXtbNNes29
 GitHub: https://github.com/ril3y/Make-Projects/blob/master/_7_segment/_7_segment.pde
 By: Riley Porter
 This is an introduction on how to drive a 7 Segment LED using only a Arduino.  This is 
 not the best way to do this.  This is meant to be a learning excercise.  In later tutorials
 I will show you how to use an dedicated IC using SPI or a Shift Register.  Enjoy.
 
 
 digitalWrite(A, HIGH) = turn off the "A" segment in the LED display
 digitalWrite(B, LOW)  = turn on the "B" segment in the LED display
 
 */

const int B = 9;
const int C = 2;
const int E = 4;
const int F = 5;
const int G = 6;

void setup()
{
  //Setup our pins
  pinMode(F, OUTPUT);
  Serial.begin(9600);  //Begin serial communcation

}

void loop()
{
  Serial.println("Starting\n");
  digitalWrite(F, 0);
  delay(100);
}
