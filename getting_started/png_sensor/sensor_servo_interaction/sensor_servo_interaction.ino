
  /**
 * Setup
 * -----
 *
 *  Using the PNG))) HC-SR04 sensor, hook up the following
 *    VCC  -> 5v out
 *    GND  -> GND
 *    Trig -> 8
 *    Echo -> 13
 *
 * As for LEDs, hook up the following:
 *   LED red -> 10
 *   LED green -> 6
 * 
 * Add a pull-down resistor to the LEDs.
 *
 * For reference on HC-SR04, refer to the following article:
 * http://winkleink.blogspot.com.au/2012/05/arduino-hc-sr04-ultrasonic-distance.html
 */
#include <Servo.h>

//Sensor setup
int echo     = 13;
int trigger  = 8;

//Servo setup
Servo servo;
int servoOut = 3;

void setup() 
{
    Serial.begin(9600);
    
    servo.attach(servoOut);
    
    pinMode(trigger, OUTPUT);
    pinMode(echo,    INPUT );
}

void loop() {
    int duration, distance;
    
    // Firing off sensor
    digitalWrite(trigger, LOW);
    delayMicroseconds(2);
    
    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger, LOW);
    
    duration = pulseIn(echo, HIGH);
    
    if( duration < 850 ) {
        int pos = map(duration, 1,850,1,180);
         servo.write(pos);
         
    }
    
    delay(250);
}
