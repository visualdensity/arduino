#if defined(ARDUINO) && ARDUINO >= 100
    #include "Arduino.h"
#endif
#include "DuinoDriver.h"

/*
 * Setups and configs
 */
    void DuinoDriver::setSideA( HDriver d ) 
    {
        this->setupSide( SIDE_A, d );
    }//setSideA

    void DuinoDriver::setSideB( HDriver d )
    {
        this->setupSide( SIDE_B, d );
    }//setSideB

    void DuinoDriver::setupSide( Sides side, HDriver d )
    {
        if( d.inputA && d.inputB && d.speed ) {

            this->driverConf[side] = d;

            pinMode( d.enablePin, OUTPUT );
            pinMode( d.inputA,    OUTPUT );
            pinMode( d.inputB,    OUTPUT );

        }
    }//setupSides

/*
 * On/Off
 */
    void DuinoDriver::motorOff( Sides side )
    {
        digitalWrite( this->driverConf[side].enablePin, LOW );
    }//motorOff

    void DuinoDriver::motorOn( Sides side )
    {
        digitalWrite( this->driverConf[side].enablePin, HIGH );
    }//motorOn

    /**
     * Both motors Off
     */
    void DuinoDriver::motorsOff()
    {
        digitalWrite( this->driverConf[SIDE_A].enablePin, LOW );
        digitalWrite( this->driverConf[SIDE_B].enablePin, LOW );
    }//motorsOff

    /**
     * Both motors On
     */
    void DuinoDriver::motorsOn()
    {
        digitalWrite( this->driverConf[SIDE_A].enablePin, HIGH );
        digitalWrite( this->driverConf[SIDE_B].enablePin, HIGH );
    }//motorsOn


/*
 * Movements
 */
    void DuinoDriver::forward()
    {
        analogWrite(  this->driverConf[SIDE_A].inputA, this->driverConf[SIDE_A].speed );
        digitalWrite( this->driverConf[SIDE_A].inputB, LOW  );

        analogWrite(  this->driverConf[SIDE_B].inputA, this->driverConf[SIDE_B].speed );
        digitalWrite( this->driverConf[SIDE_B].inputB, LOW  );
    }//forward

    void DuinoDriver::reverse()
    {
        digitalWrite( this->driverConf[SIDE_A].inputA, LOW  );
        analogWrite(  this->driverConf[SIDE_A].inputB, this->driverConf[SIDE_A].speed );

        digitalWrite( this->driverConf[SIDE_B].inputA, LOW  );
        analogWrite(  this->driverConf[SIDE_B].inputB, this->driverConf[SIDE_B].speed );
    }//reverse

    void DuinoDriver::left()
    {
        analogWrite(  this->driverConf[SIDE_A].inputA, this->driverConf[SIDE_A].speed );
        digitalWrite( this->driverConf[SIDE_A].inputB, LOW  );

        digitalWrite( this->driverConf[SIDE_B].inputA, LOW  );
        analogWrite(  this->driverConf[SIDE_B].inputB, this->driverConf[SIDE_B].speed );
    }//left

    void DuinoDriver::right()
    {
        digitalWrite( this->driverConf[SIDE_A].inputA, LOW  );
        analogWrite(  this->driverConf[SIDE_A].inputB, this->driverConf[SIDE_A].speed );

        analogWrite(  this->driverConf[SIDE_B].inputA, this->driverConf[SIDE_B].speed );
        digitalWrite( this->driverConf[SIDE_B].inputB, LOW  );
    }//right

