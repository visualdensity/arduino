#include <Bridge.h>
#include <YunServer.h>
#include <YunClient.h> 

YunServer server;
String startString;

void setup() {
    Serial.begin(9600);

    // Bridge startup
    pinMode(13,OUTPUT);
    digitalWrite(13, LOW);

    Bridge.begin();
    digitalWrite(13, HIGH);

    server.listenOnLocalhost();
    server.begin();
}//setup


void loop() {

    YunClient client = server.accept();

    if (client) {
        String command = client.readString();
        command.trim();
        Serial.println(command);

        if (command == "status") {
            client.print( analogRead(A0) );
        }

        client.stop();
    }

    delay(50);
}//loop
