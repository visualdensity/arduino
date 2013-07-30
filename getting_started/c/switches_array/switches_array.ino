#define TOTAL_SWITCHES 2

int switchesStates[TOTAL_SWITCHES];
int inByte = 0;

void setup()
{
    Serial.begin(9600);
    for( int i=0; i<TOTAL_SWITCHES; i++  ) {
        pinMode( i+2, INPUT);
        switchesStates[i] = 0;
    }
    handShake();
}

void loop()
{
    if (Serial.available() > 0 && Serial.read() == 'Z') {
      inByte = Serial.read();
        for( int i=0; i<TOTAL_SWITCHES; i++ ) {
            switchesStates[i] = digitalRead(i+2);
            Serial.write(i);
            Serial.write(switchesStates[i]);
            //Serial.println("ID:" + String(i) + " State: " + switchesStates[i] );
        }
            //Serial.println("=======================");
            //Serial.println();
    }
}


void handShake()
{
    //Keep sending hello until I get something back
    while (Serial.available() <= 0) {
      Serial.print('Z');
      delay(200);
    }    
}
