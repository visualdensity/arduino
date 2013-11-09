

int soundInput = A0;
int soundValue = 0;

int peakThreshold = 40;
unsigned long lastPeakTime  = 0;

int runState = 0;
int runDelay = 3000;

int outputPin   = 6; //needs to be PWM
int outputValue = 100;

void setup() {
  Serial.begin(9600);
  pinMode( outputPin, OUTPUT );
}

void loop() {
  soundValue = analogRead(soundInput);
  
  if( (soundValue > peakThreshold) && runState == 0 ) {
    runState = 1;    
    lastPeakTime = millis();
  }
  
  if( (millis() - lastPeakTime > runDelay ) && runState == 1 ) {
    runState = 0;
  }
  
  if( runState == 1 ) {
    analogWrite( outputPin, outputValue );
  } else {
    analogWrite( outputPin, 0 );
  }
  
  Serial.println( "A0:" + String(soundValue) + " State:" + String(runState) + " Last:" + String(lastPeakTime) );

  delay(25);
}
