#include <Adafruit_NeoPixel.h>

#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(16, PIN, NEO_GRB + NEO_KHZ800);
uint16_t count = 0;

void setup() {
  
  Serial.begin(9600);
  strip.begin();
  
  strip.setBrightness(3);

  strip.setBrightness(3);
  /strip.setPixelColor(0, 255, 0, 255);
  strip.setPixelColor(15, 255, 0, 255);
  
  
  //strip.setPixelColor(0, 255, 0, 255);
  //strip.setPixelColor(4, 255, 0, 255);
  //strip.setPixelColor(8, 255, 0, 255);
  //strip.setPixelColor(12, 255, 0, 255);
  
  //strip.setPixelColor(2, 255, 255, 20);
  //strip.setPixelColor(6, 255, 255, 20);
  //strip.setPixelColor(10, 255, 255, 20);
  //strip.setPixelColor(14, 255, 255, 20);

  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
}


