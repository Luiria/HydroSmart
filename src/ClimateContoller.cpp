#include <Arduino.h>

#include "DHTSensor.hpp"
#include "IDataPublisher.hpp"

#include "ClimateController.hpp"

ClimateController::ClimateController(DHTSensor &s, IDataPublisher &p) : sensor(s), publisher(p) {};

void ClimateController::update()
{
    sensor.read();

    publisher.sendData("temperature", sensor.getTemperature());
    publisher.sendData("humidity", sensor.getHumidity());
}