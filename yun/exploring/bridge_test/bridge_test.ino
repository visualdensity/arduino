/*
  Arduino Yun Bridge example
  http://arduino.cc/en/Tutorial/Bridge
 */

#include <Bridge.h>
#include <YunServer.h>
#include <YunClient.h>

YunServer server;

int led   = 13;
int input = A0;

int flashy = 0;

void setup() {  
   
    // Bridge startup
    pinMode(13,OUTPUT);
    digitalWrite(13, LOW);
    Bridge.begin();
    digitalWrite(13, HIGH);
    
    server.listenOnLocalhost();
    server.begin();

    // Get serial output happening
    Serial.begin(9600);
  
    // Wait until a Serial Monitor is connected.
    //while (!Serial);

    // Other setups
    pinMode( led, OUTPUT );
}

void loop() {

    int inputReading = analogRead( input );
    Serial.println( "Input: " + String(inputReading) );
    
    // Get clients coming from server
    YunClient client = server.accept();

    if (client) {
        client.print("Input: ");
        client.println( inputReading );
    
        String context = client.readStringUntil('/');
        int state = client.parseInt();
    
        if(state == 1) {
            digitalWrite( led, HIGH );
            flashy = 0;
        } else if (state == 2) {
            flashy = 1;
        } else {
            digitalWrite( led, LOW );
            flashy = 0;
        }
        
        client.print("Context: ");
        client.println(context);
        client.print("State: ");
        client.println(state);
    
        client.stop();
    }
  
    if( flashy == 1 ) {
        digitalWrite( led, HIGH);
        delay(50);
        digitalWrite( led, LOW);
    }

    delay(50); // Poll every 50ms
}

