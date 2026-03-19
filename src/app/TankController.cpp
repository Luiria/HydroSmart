#include "TankController.hpp"

TankController::TankController(UltraSonicSensor &s, LedBarGraph &l,
                               Led &ledWaterTank, Lcd16x2 &lcd, Relay &relay)
    : ultraSonicSensor(s), ledBarGraph(l), ledWaterTank(ledWaterTank),
      lcd(lcd), relay(relay) {};

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
    lcd.showDataWaterTank(level, distance);

    if (this->ultraSonicSensor.getLevel() < 10)
    {
        this->relay.turnOff();
        return;
    }
    
    this->relay.turnOn();
}