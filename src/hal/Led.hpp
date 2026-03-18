#ifndef LED_H
#define LED_H

#include <Arduino.h>

class Led
{
private:
    uint8_t pin;

public:
    Led(uint8_t pin);
    void begin();
    void on();
    void off();
    void blink();
};

#endif