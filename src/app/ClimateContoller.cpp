#include <Arduino.h>

#include "./hal/DHTSensor.hpp"
#include "./infra/AdafruitPublisher.hpp"

#include "./app/ClimateController.hpp"

ClimateController::ClimateController(DHTSensor &s, IDataPublisher &p,
                                     Led &led, Potentiometer &potentiometer, Lcd16x2 &lcd)
    : dht(s), publisher(p), led(led), potentiometer(potentiometer), lcd(lcd) {};

void ClimateController::update()
{
    if (!publisher.isConnected())
    {
        this->led.off();
        return;
    }

    this->led.on();
    dht.read();
    potentiometer.read();

    int groudTemp = this->potentiometer.getValuePourcent();

    int AirTemp = this->dht.getTemperature();
    int AirHum = this->dht.getHumidity();

    lcd.showDataGroudAndAir(groudTemp, AirTemp, AirHum);

    publisher.sendData("temperature", dht.getTemperature());
    publisher.sendData("humidity", dht.getHumidity());
}