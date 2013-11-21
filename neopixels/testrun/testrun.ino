#include <Adafruit_NeoPixel.h>

#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(16, PIN, NEO_GRB + NEO_KHZ800);

uint16_t count = 0;

void setup() {
  
  Serial.begin(9600);
  strip.begin();
  strip.setBrightness(3);
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
    
  if( count > 15 ) {
    count = 0;
  }
  
  strip.setPixelColor( count, strip.Color(0,0,128) );
  strip.show();
    
  delay(100);

  strip.setPixelColor( count, strip.Color(0,0,0) );
  strip.show();
  
  Serial.println(count);
  
  count++;
}

