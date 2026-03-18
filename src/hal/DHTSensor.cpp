#include "DHTSensor.hpp"

DHTSensor::DHTSensor(uint8_t pin, DHTesp::DHT_MODEL_t type) : pin(pin), type(type) {}

void DHTSensor::begin()
{
    dht.setup(pin, type);
    String thisBoard = ARDUINO_BOARD;
    Serial.println(thisBoard);
}

void DHTSensor::read()
{
    delay(dht.getMinimumSamplingPeriod());

    setHumidity(dht.getHumidity());
    setTemperature(dht.getTemperature());
}
