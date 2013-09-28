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
        void setSideA( HDriver d );
        void setSideB( HDriver d );

        void motorOn ( Sides side );
        void motorOff( Sides side );

        void motorsOn();
        void motorsOff();

        void forward();
        void reverse();

        void left();
        void right();
    private:
        int enablePin;
        HDriver driverConf[2];

        void setupSide( Sides side, HDriver d );
};

#endif
