#ifndef RELAY_H
#define RELAY_H

#include <Arduino.h>

class Relay
{
private:
    uint8_t pin;

public:
    Relay(uint8_t pin);
    void begin();
    void turnOn();
    void turnOff();
};

#endif
