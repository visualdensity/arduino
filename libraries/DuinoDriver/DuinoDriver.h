/**
 * Motor Driver based on SN754410
 *
 * Simple class that allows develop to quickly setup 
 * simple directional movements of a vehical based
 * on two independent motors
 */
#ifndef DUINODRIVER_H
#define DUINODRIVER_H

enum Sides
{
    SIDE_A = 0,
    SIDE_B = 1
};

struct HDriver
{
    int enablePin;
    int inputA;
    int inputB;
    int speed;
};

class DuinoDriver
{
    public:
        void DuinoDriver();

        void setSideA( HDriver d );
        void setSideB( HDriver d );

        void motorOn ( int side );
        void motorOff( int side );

        void motorsOn();
        void motorsOff();

        void forward();
        void reverse();

        void left();
        void right();
    private:
        int enablePin;
        HDriver driverConf;

        void setupSide( Side side, HDriver d );
};

#endif
