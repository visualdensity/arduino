
int high = 0;

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);  // initialize serial communication
  Serial.println("Connection established...");
  pinMode( 8, OUTPUT );
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);

  if( sensorValue > 630 ) {
      digitalWrite( 8, HIGH );
  } else {
      digitalWrite( 8, LOW );
  }

  Serial.println(sensorValue);
  delay(18);
}
