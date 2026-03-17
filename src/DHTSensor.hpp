#ifndef DHTSENSOR_H
#define DHTSENSOR_H

#include <Arduino.h>
#include <DHTesp.h>

class DHTSensor
{

private:
  DHTesp dht;
  uint8_t pin;
  DHTesp::DHT_MODEL_t type;
  float temperature;
  float humidity;

public:
  DHTSensor(uint8_t pin, DHTesp::DHT_MODEL_t type = DHTesp::DHT22);
  void begin();
  void read();

  // GETTERS
  float getTemperature() const { return temperature; }
  float getHumidity() const { return humidity; }

  // SETTERs
  void setTemperature(float t) { temperature = t; }
  void setHumidity(float h) { humidity = h; }
  
};

#endif