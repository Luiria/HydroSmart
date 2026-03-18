#ifndef LCD_H
#define LCD_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

class Lcd16x2
{
private:
    LiquidCrystal_I2C lcd;

public:
    Lcd16x2(uint8_t address);
    void begin();
    void showTempAndHumidity(int level, int distance);
};

#endif