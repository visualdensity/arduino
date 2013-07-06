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

int echo     = 13;
int trigger  = 8;
int redOut   = 10;
int greenOut = 6;

void setup() 
{
    Serial.begin(9600);
    pinMode(trigger, OUTPUT);
    pinMode(echo,    INPUT );
    pinMode(redOut,  OUTPUT);
}

void loop() {
    int duration, distance;
    
    digitalWrite(trigger, LOW);
    delayMicroseconds(2);
    
    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger, LOW);
    
    duration = pulseIn(echo, HIGH);
    distance = (duration/2) / 29.1;

    if (distance >= 200 || distance <= 0)
    {
        Serial.println("Out of range");
        digitalWrite(redOut, LOW);
        digitalWrite(greenOut, HIGH);
    }
    else 
    {
        if(distance < 4 ) {
            digitalWrite(redOut, HIGH);
            digitalWrite(greenOut, LOW);
        } else {
            digitalWrite(redOut, LOW);
            digitalWrite(greenOut, HIGH);
        }

        Serial.print(distance);
        Serial.println(" cm");
    }
    delay(500);
}
