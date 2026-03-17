#include <Arduino.h>

#include "DHTesp.h"
#include <WiFi.h>
#include <WebServer.h>
#include "AdafruitIO_WiFi.h"

#include "secret.hpp"
#include "ClimateController.hpp"

#include "DHTSensor.hpp"
#include "AdafruitPublisher.hpp"

DHTSensor sensor(14, DHTesp::DHT22);

#define IO_USERNAME AdafruitIO_Username
#define IO_KEY AdafruitIO_API_KEY

#define WIFI_SSID "Wokwi-GUEST"
#define WIFI_PASS ""

IDataPublisher *publisher = new AdafruitPublisher(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);
ClimateController climat(sensor, *publisher);

void setup()
{
  Serial.begin(115200);
  Serial.println();

  sensor.begin();
  publisher->begin();
}

void loop()
{
  publisher->run();
  climat.update();

  delay(2000);
}
