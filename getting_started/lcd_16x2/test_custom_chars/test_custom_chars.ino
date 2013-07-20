/**
 * TOPWAY LCD hookup
 *
 * Reference:
 * http://www.topwaydisplay.com/Pub/Manual/LMB162ABC-Manual-Rev0.2.pdf
 *
 * Setup:
 * RS : 2
 * E  : 3
 * DB4: 4
 * DB5: 5
 * DB6: 6
 * DB7: 7
 */
 
#include <LiquidCrystal.h>

LiquidCrystal lcd(2,3,4,5,6,7);

byte p20[8] = {
    B00000,
    B00000,
    B11011,
    B11111,
    B11111,    
    B01110,
    B00100,
};

byte p40[8] = {
    B11000,
    B11000,
    B11000,
    B11000,    
    B11000,
    B11000,
    B11000,
};

byte p60[8] = {
    B11100,
    B11100,
    B11100,
    B11100,    
    B11100,
    B11100,
    B11100,
};

byte p80[8] = {
    B11110,
    B11110,
    B11110,
    B11110,    
    B11110,
    B11110,
    B11110,
};

byte p100[8] = {
    B11111,
    B11111,
    B11111,
    B11111,    
    B11111,
    B11111,
    B11111,
};

void setup() 
{
    lcd.begin(16,2);

    lcd.createChar(5,p20);
    lcd.createChar(1,p40);
    lcd.createChar(2,p60);
    lcd.createChar(3,p80);
    lcd.createChar(4,p100);
    
    lcd.setCursor(0,0);
    lcd.print("Hi! R u ok over there? :)");
    
    for(int i=0; i<16; i++) {
    lcd.setCursor(i,1);
    lcd.write(5);
    }
}

void loop()
{
}

