#include "Lcd16x2.hpp"

Lcd16x2::Lcd16x2(uint8_t address) : lcd(address, 16, 2) {};

void Lcd16x2::begin()
{
    lcd.init();
    lcd.backlight();
    lcd.print("Initializing...");
    delay(2000);
    lcd.clear();
}

void Lcd16x2::showTempAndHumidity(int level, int distance)
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Niv:");
    lcd.print(level); 
    lcd.print("%");
    lcd.setCursor(0, 1);
    lcd.print("Dist:");
    lcd.print(distance);
    lcd.print("cm");
}