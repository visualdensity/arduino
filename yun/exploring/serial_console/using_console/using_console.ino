#include <Console.h>

int LED = 7;
int BTN = 8;

int state = LOW;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BTN, INPUT);
  
  Bridge.begin();
  Console.begin(); 

  while (!Console){
    ; // wait for Console port to connect.
  }
  Console.println("You're connected to the Console!!!!");

}

void loop() { 
    int btnState = digitalRead(BTN);
    Console.println( btnState );
    delay(100);
}
