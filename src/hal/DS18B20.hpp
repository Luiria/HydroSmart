#ifndef DS18B20_H
#define DS18B20_H

#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

class DS18B20
{
private:
    uint8_t pin;
    OneWire oneWire;
    DallasTemperature sensors;
    float temperature;

public:
    DS18B20(uint8_t pin);

    void begin();
    void read();
    // float getTemperatureInCelcuis

    // GETTERS
    float getTemperature() { return this->temperature; };
};

#endif