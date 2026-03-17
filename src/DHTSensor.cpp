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

    float humidity = dht.getHumidity();
    float temperature = dht.getTemperature();

    Serial.print(dht.getStatusString());
    Serial.print("\t");
    Serial.print(humidity, 1);
    Serial.print("\t\t");
    Serial.print(temperature, 1);
    Serial.print("\t\t");
    Serial.print(dht.toFahrenheit(temperature), 1);
    Serial.print("\t\t");
    Serial.print(dht.computeHeatIndex(temperature, humidity, false), 1);
    Serial.print("\t\t");
    Serial.println(dht.computeHeatIndex(dht.toFahrenheit(temperature), humidity, true), 1);
}