#include <PS3BT.h>
#include <usbhub.h>

USB Usb;
USBHub Hub1(&Usb);
BTD Btd(&Usb);
PS3BT PS3(&Btd); 

boolean printTemperature;
boolean printAngle;

int connected = 0;

int enableA = 7;
int enableB = 2;

int motorA_A = 3;
int motorA_B = 4;

int motorB_A = 5;
int motorB_B = 6;

int motor_running = 0;

int mSpeed = 100;

void setup() {
    Serial.begin(115200);

    if (Usb.Init() == -1) {
        Serial.print(F("\r\nOSC did not start"));
        while(1); //halt
    }

    Serial.print(F("\r\nBluetooth Library initiated..."));
    motorOn();
}

void loop() {
    Usb.Task();

    if(PS3.PS3Connected) {
      
        if( connected == 0 ) {
            Serial.println("PS3 Connected");
            connected = 1;
        }
        
        if( PS3.getAnalogHat(LeftHatX)  > 137 || 
            PS3.getAnalogHat(LeftHatX)  < 117 || 
            PS3.getAnalogHat(LeftHatY)  > 137 || 
            PS3.getAnalogHat(LeftHatY)  < 117 || 
            PS3.getAnalogHat(RightHatX) > 137 || 
            PS3.getAnalogHat(RightHatX) < 117 || 
            PS3.getAnalogHat(RightHatY) > 137 || 
            PS3.getAnalogHat(RightHatY) < 117) 
        {
            Serial.print(F("\r\nLeftHatX: ")); 
            Serial.print(PS3.getAnalogHat(LeftHatX));
            Serial.print(F("\tLeftHatY: ")); 
            Serial.print(PS3.getAnalogHat(LeftHatY));

            if(!PS3.PS3NavigationConnected) {
                Serial.print(F("\tRightHatX: ")); 
                Serial.print(PS3.getAnalogHat(RightHatX));
                Serial.print(F("\tRightHatY: ")); 
                Serial.print(PS3.getAnalogHat(RightHatY));
            }
        }//AnalogHat

        //Analog button values can be read from almost all buttons
        if(PS3.getAnalogButton(L2) || PS3.getAnalogButton(R2)) {

            Serial.print(F("\r\nL2: ")); 
            Serial.print(PS3.getAnalogButton(L2));

            if(!PS3.PS3NavigationConnected) {
                Serial.print(F("\tR2: ")); 
                Serial.print(PS3.getAnalogButton(R2));
            }
        }//analogButton L2, R2

        if(PS3.getButtonClick(PS)) {
            Serial.print(F("\r\nPS"));
            PS3.disconnect();
        } else {
            if(PS3.getButtonClick(TRIANGLE)) {
                Serial.print(F("\r\nTraingle"));
            }

            if(PS3.getButtonClick(CIRCLE)) {
                Serial.print(F("\r\nCircle"));

                if( motor_running == 0 ) {
                    forward();
                    motor_running = 1;
                } else {
                    motorOff();
                    motor_running = 0;
                }
            }

            if(PS3.getButtonClick(CROSS)) {
                Serial.print(F("\r\nCross"));
            }

            if(PS3.getButtonClick(SQUARE)) {
                Serial.print(F("\r\nSquare"));
            }

            if(PS3.getButtonClick(UP)) {
                Serial.print(F("\r\nUp"));          
                if(PS3.PS3Connected) {
                    PS3.setAllOff();
                    PS3.setLedOn(LED4);
                }
            } 

            if(PS3.getButtonClick(RIGHT)) {
                Serial.print(F("\r\nRight"));
                if(PS3.PS3Connected) {
                    PS3.setAllOff();
                    PS3.setLedOn(LED1); 
                }         
            } 

            if(PS3.getButtonClick(DOWN)) {
                Serial.print(F("\r\nDown"));
                if(PS3.PS3Connected) {
                    PS3.setAllOff();
                    PS3.setLedOn(LED2);          
                }
            } 

            if(PS3.getButtonClick(LEFT)) {          
                Serial.print(F("\r\nLeft"));          
                if(PS3.PS3Connected) {
                    PS3.setAllOff();         
                    PS3.setLedOn(LED3);            
                }         
            } 

            if(PS3.getButtonClick(L1)) {
                Serial.print(F("\r\nL1"));  
            }

            if(PS3.getButtonClick(L3)) {
                Serial.print(F("\r\nL3")); 
            }

            if(PS3.getButtonClick(R1)) {
                Serial.print(F("\r\nR1"));             
            }

            if(PS3.getButtonClick(R3)) {
                Serial.print(F("\r\nR3"));
            }

            if(PS3.getButtonClick(SELECT)) {
                Serial.print(F("\r\nSelect - ")); 
                Serial.print(PS3.getStatusString());        
            } 
            if(PS3.getButtonClick(START)) {
                Serial.print(F("\r\nStart"));              
                printAngle = !printAngle;
            }                           
        }//else


        if(printAngle) {
            Serial.print(F("\r\nPitch: "));               
            Serial.print(PS3.getAngle(Pitch));                  
            Serial.print(F("\tRoll: ")); 
            Serial.print(PS3.getAngle(Roll));
        }
    } 
    
    delay(150);
}//loop

void motorOn()
{
    analogWrite(enableA, 50);
    analogWrite(enableB, 50);
}

void motorOff()
{
    digitalWrite(enableA, LOW);
    digitalWrite(enableB, LOW);
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
    
    analogWrite(motorA_B, mSpeed);
    analogWrite(motorB_B, mSpeed);
}

void left()
{
    analogWrite(motorA_A, mSpeed);
    digitalWrite(motorA_B, LOW);
    
    digitalWrite(motorB_A, LOW);
    analogWrite(motorB_B, mSpeed);
}
void right()
{
    digitalWrite(motorA_A, LOW);
    analogWrite(motorA_B, mSpeed);
    
    analogWrite(motorB_A, mSpeed);
    digitalWrite(motorB_B, LOW);
}
