#include "TankController.hpp"

TankController::TankController(UltraSonicSensor &s, LedBarGraph &l, Led &ledWaterTank)
    : ultraSonicSensor(s), ledBarGraph(l), ledWaterTank(ledWaterTank) {};

void TankController::update()
{
    // Max 400 ( plage du UltraSonicSensor : 2-400 cm)
    this->ultraSonicSensor.setTankHeight(2, 300);
    this->ultraSonicSensor.read();
    this->ledBarGraph.update(this->ultraSonicSensor.getLevel());

    if(this->ultraSonicSensor.getLevel() < 10)
        this->ledWaterTank.blink();

}