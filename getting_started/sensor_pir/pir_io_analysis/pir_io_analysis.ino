/**
 * PIR Sensor
 *
 * Setup: Looking at the 3 pins from the opposite side, 
 * GND is the leftmost pin, rightmost is the 5V  and 
 * middle pin is data. Data pin is connected to Arduino's
 * pin 13
 *
 * There is also a red LED setup with pin 7
 */

int led = 7;
int sensor = 13;
int calibrationTime = 20;

void setup()
{
    Serial.begin(9600);

    pinMode(sensor, INPUT);
    pinMode(led, OUTPUT);
    
    flashLed(2, 100);

    //give the sensor some time to calibrate
    Serial.print("calibrating sensor ");
    for(int i = 0; i < calibrationTime; i++){
        Serial.print(".");
        delay(1000);
        
    }

    flashLed(5, 200);

    Serial.println(" one");
    Serial.println("SENSOR ACTIVE");

    delay(50);
}

void flashLed(int times, int delayTime)
{
    for( int i=0; i < times; i++ ) {
        digitalWrite(led, HIGH);
        delay(delayTime);
        digitalWrite(led, LOW);
        delay(delayTime);
    }
}

void loop()
{
    if( digitalRead(sensor) == HIGH ) {
        Serial.println("There's motion!");
        digitalWrite(led, HIGH);
    } else {
        Serial.println("No motion");
        digitalWrite(led, LOW);
    }
    delay(100);
}
