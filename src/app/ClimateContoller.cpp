#include <Arduino.h>

#include "./hal/DHTSensor.hpp"
#include "./infra/AdafruitPublisher.hpp"

#include "./app/ClimateController.hpp"

ClimateController::ClimateController(DHTSensor &s, IDataPublisher &p) : sensor(s), publisher(p) {};

void ClimateController::update()
{
    sensor.read();

    publisher.sendData("temperature", sensor.getTemperature());
    publisher.sendData("humidity", sensor.getHumidity());
}