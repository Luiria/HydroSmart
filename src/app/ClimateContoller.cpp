#include <Arduino.h>

#include "./hal/DHTSensor.hpp"
#include "./infra/AdafruitPublisher.hpp"

#include "./app/ClimateController.hpp"

ClimateController::ClimateController(DHTSensor &s, IDataPublisher &p, Led &led) : sensor(s), publisher(p), led(led) {};

void ClimateController::update()
{
    if (!publisher.isConnected())
    {
        this->led.off();
        return;
    }

    this->led.on();
    sensor.read();

    publisher.sendData("temperature", sensor.getTemperature());
    publisher.sendData("humidity", sensor.getHumidity());
}