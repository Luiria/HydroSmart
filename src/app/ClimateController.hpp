#ifndef CLIMATECONTROLLER_H
#define CLIMATECONTROLLER_H

#include "./hal/DHTSensor.hpp"
#include "./hal/Led.hpp"
#include "./hal/Potentiometer.hpp"
#include "./hal/Lcd16x2.hpp"
#include "./hal/DS18B20.hpp"

#include "./infra/IDataPublisher.hpp"

class ClimateController
{
private:
    DHTSensor &dht;
    IDataPublisher &publisher;
    Led &led;
    Potentiometer &potentiometer;
    Lcd16x2 &lcd;
    DS18B20 &groundTempSensor;

public:
    ClimateController(DHTSensor &s, IDataPublisher &p, Led &led,
                      Potentiometer &potentiometer, Lcd16x2 &lcd, DS18B20 &groundTempSensor);
    void update();
};

#endif