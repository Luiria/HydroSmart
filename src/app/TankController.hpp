#ifndef TANKCONTROLLER_H
#define TANKCONTROLLER_H

#include "./hal/UltraSonicSensor.hpp"
#include "./hal/LedBarGraph.hpp"
#include "./hal/Led.hpp"
#include "./hal/Lcd16x2.hpp"
#include "./hal/Relay.hpp"

#include "./infra/IDataPublisher.hpp"

class TankController
{
private:
    UltraSonicSensor &ultraSonicSensor;
    LedBarGraph &ledBarGraph;
    Led &ledWaterTank;
    Lcd16x2 &lcd;
    Relay &relay;
    IDataPublisher &publisher;

public:
    TankController(UltraSonicSensor &s, LedBarGraph &l, Led &ledWaterTank,
                   Lcd16x2 &lcd, Relay &relay, IDataPublisher &publisher);
    void update();
};

#endif