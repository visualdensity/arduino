/*
  Arduino Yun Bridge example
 
 This example for the Arduino Yun shows how to use the 
 Bridge library to access the digital and analog pins 
 on the board through REST calls. It demonstrates how 
 you can create your own API when using REST style 
 calls through the browser.
 
 Possible commands created in this shetch:

 * "/arduino/digital/13"     -> digitalRead(13)
 * "/arduino/digital/13/1"   -> digitalWrite(13, HIGH)
 * "/arduino/analog/2/123"   -> analogWrite(2, 123)
 * "/arduino/analog/2"       -> analogRead(2)
 * "/arduino/mode/13/input"  -> pinMode(13, INPUT)
 * "/arduino/mode/13/output" -> pinMode(13, OUTPUT)
 
 This example code is part of the public domain
 
 http://arduino.cc/en/Tutorial/Bridge

 */

#include <Bridge.h>
#include <YunServer.h>
#include <YunClient.h>

// Listen on default port 5555, the webserver on the Yun
// will forward there all the HTTP requests for us.
YunServer server;
int led = 8;
int light = A4;
int flashy = 0;

void setup() {  
  pinMode( led, OUTPUT );
  
  // Bridge startup
  pinMode(13,OUTPUT);
  digitalWrite(13, LOW);
  Bridge.begin();
  digitalWrite(13, HIGH);
  
  // Listen for incoming connection only from localhost
  // (no one from the external network could connect)
  server.listenOnLocalhost();
  server.begin();
}

void loop() {
  String subject;
  int state;
  int lumens=0;
  
  lumens = analogRead( light );
  
  // Get clients coming from server
  YunClient client = server.accept();

  // There is a new client?
  if (client) {
    client.print("Light: ");
    client.println( lumens );
    
    subject = client.readStringUntil('/');
    state = client.parseInt();
    
    if(state == 1) {
      digitalWrite( led, HIGH );
      flashy = 0;
    } else if (state == 2) {
      flashy = 1;
    } else {
      digitalWrite( led, LOW );
      flashy = 0;
    }
    
    client.print("Subject ");
    client.println(subject);
    client.print("State ");
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

