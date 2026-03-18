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

#include "infra/AdafruitPublisher.hpp"

#define IO_USERNAME AdafruitIO_Username
#define IO_KEY AdafruitIO_API_KEY

#define WIFI_SSID WIFI_SSID
#define WIFI_PASS WIFI_PASS

Led ledConnectedToAdafruit(12);
Led ledWaterTank(13);

int ledPins[] = {0, 4, 16, 17, 5, 18, 19, 25, 33, 23};

DHTSensor sensor(14, DHTesp::DHT22);
UltraSonicSensor ultraSonicSensor(27, 26);
LedBarGraph ledBarGraph(ledPins);

IDataPublisher *publisher = new AdafruitPublisher(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);

ClimateController climat(sensor, *publisher, ledConnectedToAdafruit);
TankController tankController(ultraSonicSensor, ledBarGraph, ledWaterTank);

void setup()
{
  Serial.begin(115200);
  Serial.println();

  publisher->begin();

  sensor.begin();
  ledConnectedToAdafruit.begin();

  ultraSonicSensor.begin();
  ledBarGraph.begin();
  ledBarGraph.initLed();

  ledWaterTank.begin();
}

void loop()
{
  publisher->run();
  climat.update();

  tankController.update();
  
  delay(5000);
}
