#ifndef TANKCONTROLLER_H
#define TANKCONTROLLER_H

#include "./hal/UltraSonicSensor.hpp"
#include "./hal/LedBarGraph.hpp"

class TankController
{
private:
    UltraSonicSensor &ultraSonicSensor;
    LedBarGraph &ledBarGraph;

public:
    TankController(UltraSonicSensor &s, LedBarGraph &l);
    void update();
};

#endif