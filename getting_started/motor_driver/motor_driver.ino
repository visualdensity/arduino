#include <Bounce.h>

int enableA = 7;
int enableB = 12;

int buttonDown  = 2;
int buttonUp    = 3;
int buttonLeft  = 4;
int buttonRight = 5;

int motorA_A = 6;
int motorA_B = 9;

int motorB_A = 10;
int motorB_B = 11;

unsigned long firstTime;

Bounce forwardButton = Bounce( buttonUp, 5 ); 
Bounce reverseButton = Bounce( buttonDown, 5 );
Bounce leftButton    = Bounce( buttonLeft, 5 );
Bounce rightButton   = Bounce( buttonRight, 5 );

void setup()
{
    Serial.begin(9600);
    
    pinMode(buttonDown,  INPUT);
    pinMode(buttonUp,    INPUT);
    pinMode(buttonLeft,  INPUT);
    pinMode(buttonRight, INPUT);
    
    pinMode(enableA, OUTPUT);
    pinMode(enableB, OUTPUT);
    
    pinMode(motorA_A,  OUTPUT);
    pinMode(motorA_B,  OUTPUT);
    
    pinMode(motorB_A,  OUTPUT);
    pinMode(motorB_B,  OUTPUT);
    
    motorOn();
}

void loop()
{
    forwardButton.update();
    reverseButton.update();
    leftButton.update();
    rightButton.update();
    
    if( forwardButton.read() == HIGH ) {
        Serial.println("Forward");
        //motorOn();
        forward();
    } else {
        //motorOff();
    }
    
    if( reverseButton.read() == HIGH ) {
        Serial.println("Reverse");
        //motorOn();
        reverse();
    } else {
        //motorOff();
    }
    
    if( leftButton.read() == HIGH ) {
        Serial.println("Left");
        //motorOn();
        left();
    } else {
        //motorOff();
    }
    
    if( rightButton.read() == HIGH ) {
        Serial.println("Right");
        //motorOn();
        right();
    } else {
        //motorOff();
    }
    
    delay(150);
}


void motorOn()
{
    digitalWrite(enableA, HIGH);
    digitalWrite(enableB, HIGH);
    //digitalWrite(enableLed, HIGH);
}

void motorOff()
{
    digitalWrite(enableA, LOW);
    digitalWrite(enableB, LOW);
    //digitalWrite(enableLed, LOW);
}

void reverse()
{
    digitalWrite(motorA_A, HIGH);
    digitalWrite(motorB_A, HIGH);
    
    digitalWrite(motorA_B, LOW);
    digitalWrite(motorB_B, LOW);
}

void forward()
{
    digitalWrite(motorA_A, LOW);
    digitalWrite(motorB_A, LOW);
    
    digitalWrite(motorA_B, HIGH);
    digitalWrite(motorB_B, HIGH);
}

void left()
{
    digitalWrite(motorA_A, HIGH);
    digitalWrite(motorA_B, LOW);
    
    digitalWrite(motorB_A, LOW);
    digitalWrite(motorB_B, HIGH);
}
void right()
{
    digitalWrite(motorA_A, LOW);
    digitalWrite(motorA_B, HIGH);
    
    digitalWrite(motorB_A, HIGH);
    digitalWrite(motorB_B, LOW);
}
