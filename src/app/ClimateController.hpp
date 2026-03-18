#ifndef CLIMATECONTROLLER_H
#define CLIMATECONTROLLER_H

#include "./hal/DHTSensor.hpp"
#include "./hal/Led.hpp"
#include "./hal/Potentiometer.hpp"
#include "./hal/Lcd16x2.hpp"
#include "./infra/IDataPublisher.hpp"

class ClimateController
{
private:
    DHTSensor &dht;
    IDataPublisher &publisher;
    Led &led;
    Potentiometer &potentiometer;
    Lcd16x2 &lcd;

public:
    ClimateController(DHTSensor &s, IDataPublisher &p, Led &led, Potentiometer &potentiometer, Lcd16x2 &lcd);
    void update();
};

#endif