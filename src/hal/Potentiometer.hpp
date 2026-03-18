#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

#include <Arduino.h>

class Potentiometer
{
private:
    uint8_t pin;
    int value;

public:
    Potentiometer(uint8_t pin);
    void begin();
    void read();
    int getValuePourcent();

    // GETTERS
    int getValue() { return this->value; };

    // SETTERS
    void setValue(int value) { this->value = value; };
};

#endif
