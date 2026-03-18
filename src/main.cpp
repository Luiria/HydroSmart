#include <Arduino.h>

#include "DHTesp.h"
#include <WiFi.h>
#include <WebServer.h>
#include "AdafruitIO_WiFi.h"

#include "secret.hpp"
#include "app/ClimateController.hpp"

#include "hal/DHTSensor.hpp"
#include "./hal/Led.hpp"

#include "infra/AdafruitPublisher.hpp"

DHTSensor sensor(14, DHTesp::DHT22);
Led ledConnectedToAdafruit(2);

#define IO_USERNAME AdafruitIO_Username
#define IO_KEY AdafruitIO_API_KEY

#define WIFI_SSID WIFI_SSID
#define WIFI_PASS WIFI_PASS 

IDataPublisher *publisher = new AdafruitPublisher(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);
ClimateController climat(sensor, *publisher, ledConnectedToAdafruit);

void setup()
{
  Serial.begin(115200);
  Serial.println();

  publisher->begin();
  sensor.begin();
  ledConnectedToAdafruit.begin();
}

void loop()
{
  publisher->run();
  climat.update();
  delay(5000);
}
