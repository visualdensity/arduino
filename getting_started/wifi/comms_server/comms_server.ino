/**
 * Note that these pins are in use
 * by the WiFi shield on Uno R3
 *
 *  - 10, 4, 7
 */

#include <SPI.h>
#include <WiFi.h>

char ssid[] = "noneofyourbusiness";
char pass[] = "waj192oakleigh";

int keyIndex = 0;
int status = WL_IDLE_STATUS;

int redLed = 2;
int greenLed = 3;

boolean alreadyConnected = false;
WiFiServer server(23);


void ledNotify(int times, int sleep=120) {    
    for( int i=0; i<times; i++ ) {
        digitalWrite(redLed, HIGH);
        delay(sleep);
        digitalWrite(redLed, LOW);
        delay(sleep);
    }
}

void setup() {

  Serial.begin(9600); 
  
  pinMode( redLed, OUTPUT );
  pinMode( greenLed, OUTPUT );
  
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present"); 
    while(true);
  }
  
  ledNotify(2, 80);
  while ( status != WL_CONNECTED) { 
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);

    delay(10000);
  }

  server.begin();
  ledNotify(5);
  printWifiStatus();
 }


void loop() {
  WiFiClient client = server.available();

  if (client) {
    if (!alreadyConnected) {
      client.flush();    
      Serial.println("We have a new client");
      client.println("Hello, client!"); 
      alreadyConnected = true;
    } 

    if (client.available() > 0) {

      char thisChar = client.read();
      if( thisChar == 'R' ) {
          digitalWrite( redLed, HIGH );
      } 
      
      if( thisChar == 'G' ) {
          digitalWrite( greenLed, HIGH );
      }
      
      if( thisChar == 'X' ) {
          digitalWrite( greenLed, LOW );
          digitalWrite( redLed, LOW );
      }
    }
  }
  
  delay(100);
}


void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
  
  Serial.print("Gateway: ");
  Serial.println(WiFi.gatewayIP() );
  
  Serial.print("Subnet Mask: ");
  Serial.println(WiFi.subnetMask() );

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}
