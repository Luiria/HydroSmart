#include "Led.hpp"

Led::Led(uint8_t pin) : pin(pin) {};

void Led::begin(){
    pinMode(this->pin, OUTPUT);
}

void Led::on(){
    digitalWrite(this->pin, HIGH);
}

void Led::off(){
    digitalWrite(this->pin, LOW);
}
