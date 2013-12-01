#include <Bridge.h>
#include <YunServer.h>
#include <YunClient.h> 

YunServer server;
String startString;

int led = 11;
int ledState = 0;

void setup() {
    Serial.begin(9600);

    pinMode(13,OUTPUT);
    digitalWrite(13, LOW);

    Bridge.begin();
    digitalWrite(13, HIGH);

    Bridge.begin();
    Console.begin();
    
    //while (!Console){
    //    ; // wait for Console port to connect.
    //}
    //Console.println("You're connected to the Console!!!!");
  
    server.listenOnLocalhost();
    server.begin();
}//setup


void loop() {

    YunClient client = server.accept();

    if (client) {

        String command = client.readString();
        command.trim();
        //Console.println(command);

        if (command == "status") {
            client.print( analogRead(A0) );
        }
        
        if (command == "led/status") {
            client.print( ledState );
        }
        
        if ( command == "led/on" ) {
            analogWrite( led, 50 );
            ledState = 1;
            client.print( "1" );
        }

        if ( command == "led/off" ) {
            analogWrite( led, 0 );
            ledState = 0;
            client.print( "0" );
        }
        
        client.stop();
    }

    delay(50);
}//loop
