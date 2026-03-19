#include <Arduino.h>

#include "DHTesp.h"
#include <WiFi.h>
#include <WebServer.h>
#include "AdafruitIO_WiFi.h"

#include "secret.hpp"
#include "app/ClimateController.hpp"
#include "./app/TankController.hpp"

#include "hal/DHTSensor.hpp"
#include "./hal/Led.hpp"
#include "./hal/LedBarGraph.hpp"
#include "./hal/UltraSonicSensor.hpp"
#include "./hal/Lcd16x2.hpp"
#include "./hal/Potentiometer.hpp"
#include "./hal/DS18B20.hpp"
#include "./hal/Relay.hpp"

#include "infra/AdafruitPublisher.hpp"

#define IO_USERNAME AdafruitIO_Username
#define IO_KEY AdafruitIO_API_KEY

#define WIFI_SSID WIFI_SSID
#define WIFI_PASS WIFI_PASS

Led ledConnectedToAdafruit(12);
Led ledWaterTank(13);

Lcd16x2 lcdWaterTank(0x27);
Lcd16x2 lcdClimatSensors(0x26);

Potentiometer potentiometer(32);
DS18B20 groundTempSensor(15);
Relay relay(0);

int ledPins[] = {2, 4, 16, 17, 5, 18, 19, 25, 33, 23};

DHTSensor sensor(14, DHTesp::DHT22);
UltraSonicSensor ultraSonicSensor(27, 26);
LedBarGraph ledBarGraph(ledPins);

IDataPublisher *publisher = new AdafruitPublisher(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);

ClimateController climat(sensor, *publisher, ledConnectedToAdafruit, potentiometer, lcdClimatSensors, groundTempSensor);
TankController tankController(ultraSonicSensor, ledBarGraph, ledWaterTank, lcdWaterTank, relay);

void setup()
{
  Serial.begin(115200);
  Serial.println();

  publisher->begin();

  sensor.begin();
  ledConnectedToAdafruit.begin();

  Wire.begin(21, 22);
  lcdWaterTank.begin();
  lcdClimatSensors.begin();

  groundTempSensor.begin();

  ultraSonicSensor.begin();
  ledBarGraph.begin();
  ledBarGraph.initLed();

  ledWaterTank.begin();

  relay.begin();
}

void loop()
{
  publisher->run();
  climat.update();

  tankController.update();
}