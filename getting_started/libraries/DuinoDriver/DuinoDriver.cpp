#if defined(ARDUINO) && ARDUINO >= 100
    #include "Arduino.h"
#endif
#include "DuinoDriver.h"

/*
 * Setups and configs
 */
    void DuinoDriver::setEnablePin( int side, int pin )
    {
        if( side == SIDE_A ) {
            this->sideA[ENABLE_PIN] = pin;
        } else if( side == SIDE_B ) {
            this->sideB[ENABLE_PIN] = pin;
        } 

        pinMode( pin, OUTPUT);
    }//setEnablePin

    void DuinoDriver::setInputA(int side, int pin)
    {
        if( side == SIDE_A ) {
            this->sideA[INPUT_A] = pin;
        } else if ( side == SIDE_B ) {
            this->sideB[INPUT_A] = pin;
        }
        pinMode( pin, OUTPUT);
    }//setInputA

    void DuinoDriver::setInputB(int side, int pin)
    {
        if( side == SIDE_A ) {
            this->sideA[INPUT_B] = pin;
        } else if ( side == SIDE_B ) {
            this->sideB[INPUT_B] = pin;
        }
        pinMode( pin, OUTPUT);
    }//setInputB

    void DuinoDriver::setMaxSpeed( int maxSpeed )
    {
        if( maxSpeed < 256 ) {
            this->maxSpeed = maxSpeed;
        } else {
            this->maxSpeed = 100;
        }
    }

/*
 * On/Off
 */
    void DuinoDriver::motorOff(int side)
    {
        if( side == SIDE_A ) {
            digitalWrite(this->sideA[ENABLE_PIN], 0);
        } else if ( side == SIDE_B ) {
            digitalWrite(this->sideB[ENABLE_PIN], 0);
        }
    }//motorOff

    void DuinoDriver::motorOn(int side)
    {
        if( side == SIDE_A ) {
            digitalWrite(this->sideA[ENABLE_PIN], 1);
        } else if ( side == SIDE_B ) {
            digitalWrite(this->sideB[ENABLE_PIN], 1);
        }
    }//motorOn

    void DuinoDriver::motorsOff()
    {
        digitalWrite(this->sideA[ENABLE_PIN], 0);
        digitalWrite(this->sideB[ENABLE_PIN], 0);
    }//motorsOff

    void DuinoDriver::motorsOn()
    {
        digitalWrite(this->sideA[ENABLE_PIN], 1);
        digitalWrite(this->sideB[ENABLE_PIN], 1);
    }//motorsOn


/*
 * Movements
 */
    void DuinoDriver::forward()
    {
        analogWrite(this->sideA[OUTPUT_A], 100);
        digitalWrite(this->sideA[OUTPUT_B], 0);
        
        analogWrite(this->sideB[OUTPUT_A], 100);
        digitalWrite(this->sideB[OUTPUT_B], 0);
    }//forward

    void DuinoDriver::reverse()
    {
        digitalWrite(this->sideA[OUTPUT_A], 0);
        digitalWrite(this->sideA[OUTPUT_B], 1);
                                          
        digitalWrite(this->sideB[OUTPUT_A], 0);
        digitalWrite(this->sideB[OUTPUT_B], 1);
    }//reverse

    void DuinoDriver::left()
    {
        digitalWrite(this->sideA[OUTPUT_A], 1);
        digitalWrite(this->sideA[OUTPUT_B], 0);
                                          
        digitalWrite(this->sideB[OUTPUT_A], 0);
        digitalWrite(this->sideB[OUTPUT_B], 1);
    }//left

    void DuinoDriver::right()
    {
        digitalWrite(this->sideA[OUTPUT_A], 0);
        digitalWrite(this->sideA[OUTPUT_B], 1);
                                          
        digitalWrite(this->sideB[OUTPUT_A], 1);
        digitalWrite(this->sideB[OUTPUT_B], 0);
    }//right

