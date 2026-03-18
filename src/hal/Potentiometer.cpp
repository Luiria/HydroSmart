#include "Potentiometer.hpp"

Potentiometer::Potentiometer(uint8_t pin) : pin(pin) {};

void Potentiometer::begin()
{
    pinMode(this->pin, INPUT);
}

void Potentiometer::read()
{
    int newValue = analogRead(this->pin);
    this->setValue(newValue);
}

int Potentiometer::getValuePourcent()
{
    return this->value * 100 / 4095;
}