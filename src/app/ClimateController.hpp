#ifndef CLIMATECONTROLLER_H
#define CLIMATECONTROLLER_H

#include "./hal/DHTSensor.hpp"
#include "./hal/Led.hpp"
#include "./infra/IDataPublisher.hpp"

class ClimateController
{
private:
    DHTSensor &sensor;
    IDataPublisher &publisher;
    Led &led;

public:
    ClimateController(DHTSensor &s, IDataPublisher &p, Led &led);
    void update();
};

#endif