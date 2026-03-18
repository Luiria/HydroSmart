#include "TankController.hpp"

TankController::TankController(UltraSonicSensor &s, LedBarGraph &l,
                               Led &ledWaterTank, Lcd16x2 &lcd)
    : ultraSonicSensor(s), ledBarGraph(l), ledWaterTank(ledWaterTank), lcd(lcd) {};

void TankController::update()
{
    // Max 400 ( plage du UltraSonicSensor : 2-400 cm)
    this->ultraSonicSensor.setTankHeight(2, 400);
    this->ultraSonicSensor.read();
    this->ledBarGraph.update(this->ultraSonicSensor.getLevel());

    if (this->ultraSonicSensor.getLevel() < 10)
        this->ledWaterTank.blink();

    int distance = this->ultraSonicSensor.getDistance();
    int level = this->ultraSonicSensor.getLevel();

    lcd.showTempAndHumidity(level, distance);
}