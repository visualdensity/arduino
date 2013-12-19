/*
 * ********* Doorbell Basic BELL ********
 * requires pre-paired XBee Radios
 * and the BUTTON program on the receiving end
 * by Rob Faludi http://faludi.com
 */

#define VERSION "1.00a0"

int LED  = 11;
int BELL = 5;


void setup() {
  pinMode(BELL, OUTPUT);
  pinMode(LED, OUTPUT);

  Serial.begin(9600);
}


void loop() {
  // look for a capital D over the serial port and ring the bell if found
  if (Serial.available() > 0) {
    if (Serial.read() == 'D'){
      digitalWrite(LED, HIGH);
      analogWrite(BELL, 150);
      delay(20);
      digitalWrite(BELL, LOW);
      digitalWrite(LED, LOW);
    }
  }
}
