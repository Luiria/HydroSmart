#ifndef TANKCONTROLLER_H
#define TANKCONTROLLER_H

#include "./hal/UltraSonicSensor.hpp"
#include "./hal/LedBarGraph.hpp"
#include "./hal/Led.hpp"
#include "./hal/Lcd16x2.hpp"
#include "./hal/Relay.hpp"

class TankController
{
private:
    UltraSonicSensor &ultraSonicSensor;
    LedBarGraph &ledBarGraph;
    Led &ledWaterTank;
    Lcd16x2 &lcd;
    Relay &relay;

public:
    TankController(UltraSonicSensor &s, LedBarGraph &l, Led &ledWaterTank, Lcd16x2 &lcd, Relay &relay);
    void update();
};

#endif