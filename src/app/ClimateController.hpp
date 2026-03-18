#ifndef CLIMATECONTROLLER_H
#define CLIMATECONTROLLER_H

#include "./hal/DHTSensor.hpp"
#include "./infra/IDataPublisher.hpp"

class ClimateController
{
private:
    DHTSensor &sensor;
    IDataPublisher &publisher;

public:
    ClimateController(DHTSensor &s, IDataPublisher &p);
    void update();
};

#endif