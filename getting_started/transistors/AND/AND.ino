/**
 * Manual transistor AND gate
 * 
 * Just an experiment to demonstrate an AND 
 * gate using a standard NPN transistor
 */

int transistor1 = 12;
int transistor2 = 11;

void setup() {
  pinMode(transistor1, OUTPUT);
  pinMode(transistor2, OUTPUT);
  
  digitalWrite(transistor1, HIGH);
  digitalWrite(transistor2, HIGH);
}

void loop() {
}
