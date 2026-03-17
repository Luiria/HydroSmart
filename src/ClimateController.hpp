#ifndef CLIMATECONTROLLER_H
#define CLIMATECONTROLLER_H

#include "DHTSensor.hpp"
#include "IDataPublisher.hpp"

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