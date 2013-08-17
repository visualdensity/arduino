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
        else if( side == SIDE_B ) {
            this->sideB[ENABLE_PIN] = pin;
        } else {
            return false;
        }
    }//setEnablePin

    void DuinoDriver::setOutputA(int side, int pin)
    {
        if( side == SIDE_A ) {
            this->sideA[OUTPUT_A] = pin;
        } else if ( side == SIDE_B ) {
            this->sideB[OUTPUT_A] = pin;
        } else {
            return false;
        }
    }//setOuputA

    void DuinoDriver::setOutputB(int side, int pin)
    {
        if( side == SIDE_A ) {
            this->sideA[OUTPUT_B] = pin;
        } else if ( side == SIDE_B ) {
            this->sideB[OUTPUT_B] = pin;
        } else {
            return false;
        }
    }//setOutputB

    void DuinoDriver::setInputA(int side, int pin)
    {
        if( side == SIDE_A ) {
            this->sideA[INPUT_A] = pin;
        } else if ( side == SIDE_B ) {
            this->sideB[INPUT_A] = pin;
        } else {
            return false;
        }
    }//setInputA

    void DuinoDriver::setInputB(int side, int pin)
    {
        if( side == SIDE_A ) {
            this->sideA[INPUT_B] = pin;
        } else if ( side == SIDE_B ) {
            this->sideB[INPUT_B] = pin;
        } else {
            return false;
        }
    }//setInputB


/*
 * On/Off
 */
    void DuinoDriver::motorOff(int side)
    {
        if( side == SIDE_A ) {
            digitalWrite(this->sideA[ENABLE_PIN], 0);
        } else if ( side == SIDE_B ) {
            digitalWrite(this->sideB[ENABLE_PIN], 0);
        } else {
            return false;
        }
    }//motorOff

    void DuinoDriver::motorOn(int side)
    {
        if( side == SIDE_A ) {
            digitalWrite(this->sideA[ENABLE_PIN], 1);
        } else if ( side == SIDE_B ) {
            digitalWrite(this->sideB[ENABLE_PIN], 1);
        } else {
            return false;
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
        digitalWrite(this->sideA[OUTPUT_A], 1);
        digitalWrite(this->sideA[OUTPUT_B], 0);
        
        digitalWrite(this->sideB[OUTPUT_A], 1);
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

