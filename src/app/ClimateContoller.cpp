#include <Arduino.h>

#include "./hal/DHTSensor.hpp"
#include "./infra/AdafruitPublisher.hpp"

#include "./app/ClimateController.hpp"

ClimateController::ClimateController(DHTSensor &s, IDataPublisher &p, Led &led,
                                     Potentiometer &potentiometer, Lcd16x2 &lcd,
                                     DS18B20 &groundTempSensor)
    : dht(s), publisher(p), led(led), potentiometer(potentiometer),
      lcd(lcd), groundTempSensor(groundTempSensor) {};

void ClimateController::update()
{
    if (!publisher.isConnected())
    {
        this->led.off();
        return;
    }

    this->led.on();
    this->dht.read();
    this->potentiometer.read();
    this->groundTempSensor.read();

    int groundTemp = this->groundTempSensor.getTemperature();
    int groundHum = this->potentiometer.getValuePourcent();

    int AirTemp = this->dht.getTemperature();
    int AirHum = this->dht.getHumidity();

    lcd.showDataGroudAndAir(groundTemp, groundHum, AirTemp, AirHum);

    publisher.sendData("temperature", dht.getTemperature());
    publisher.sendData("humidity", dht.getHumidity());
}