//http://winkleink.blogspot.com.au/2012/05/arduino-hc-sr04-ultrasonic-distance.html

int echo = 13;
int trigger = 8;

void setup() {
  Serial.begin(9600);
  pinMode(trigger, OUTPUT);
  pinMode(echo,    INPUT );
}

void loop() {
  int duration, distance;
  
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  
  duration = pulseIn(echo, HIGH);
  
  Serial.println( "Echo:" );
  Serial.println( duration );

  distance = (duration/2) / 29.1;
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(500);
}
