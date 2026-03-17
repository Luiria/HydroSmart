#ifndef DHTSENSOR_H
#define DHTSENSOR_H

#include <Arduino.h>
#include <DHTesp.h>

class DHTSensor {
  
  private:
    DHTesp dht;
    uint8_t pin;
    DHTesp::DHT_MODEL_t type;

  public:
    DHTSensor(uint8_t pin, DHTesp::DHT_MODEL_t type = DHTesp::DHT22);
    void begin();
    void read();
    
};

#endif