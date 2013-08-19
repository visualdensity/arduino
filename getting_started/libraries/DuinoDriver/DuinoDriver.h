/**
 * Motor Driver based on SN754410
 *
 * Simple class that allows develop to quickly setup 
 * simple directional movements of a vehical based
 * on two independent motors
 */
#ifndef DUINODRIVER_H
#define DUINODRIVER_H

#define SIDE_A 0
#define SIDE_B 1

#define ENABLE_PIN 10

#define INPUT_A 20
#define INPUT_B 21

class DuinoDriver
{
    public:
        void setEnablePin( int side, int pin );
        void setMaxSpeed( int maxSpeed );

        void setInputA( int side, int pin );
        void setInputB( int side, int pin );

        void motorOn ( int side );
        void motorOff( int side );

        void motorsOn();
        void motorsOff();

        void forward();
        void reverse();

        void left();
        void right();
    private:
        /* Used thiese 2 vars cause Arduino doesn't 
         * support vector<map<string, int> >
         */
        int sideA[3];
        int sideB[3];
        int maxSpeed;
};

#endif
