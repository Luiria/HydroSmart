#include "Relay.hpp"

Relay::Relay(uint8_t pin) : pin(pin) {};

void Relay::begin()
{
    pinMode(this->pin, OUTPUT);
    // digitalWrite(this->pin, HIGH);
}

void Relay::turnOn()
{
    digitalWrite(this->pin, LOW);
}

void Relay::turnOff()
{
    digitalWrite(this->pin, HIGH);
}
