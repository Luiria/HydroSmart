#include "DS18B20.hpp"

DS18B20::DS18B20(uint8_t pin)
    : pin(pin), oneWire(pin), sensors(&oneWire) {}

void DS18B20::begin()
{
    sensors.begin();
}

void DS18B20::read()
{
    sensors.requestTemperatures();
    temperature = sensors.getTempCByIndex(0);
}
