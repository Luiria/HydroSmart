#ifndef TANKCONTROLLER_H
#define TANKCONTROLLER_H

#include "./hal/UltraSonicSensor.hpp"
#include "./hal/LedBarGraph.hpp"
#include "./hal/Led.hpp"

class TankController
{
private:
    UltraSonicSensor &ultraSonicSensor;
    LedBarGraph &ledBarGraph;
    Led &ledWaterTank;

public:
    TankController(UltraSonicSensor &s, LedBarGraph &l, Led &ledWaterTank);
    void update();
};

#endif