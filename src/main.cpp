#include <Arduino.h>

#include "DHTesp.h"
#include <WiFi.h>
#include <WebServer.h>
#include "AdafruitIO_WiFi.h"

#include "DHTSensor.hpp"

DHTSensor sensor(14, DHTesp::DHT22);

void setup()
{
  Serial.begin(115200);
  sensor.begin();
  Serial.println();
  Serial.println("Status\tHumidity (%)\tTemperature (C)\t(F)\tHeatIndex (C)\t(F)");
}

void loop()
{
  sensor.read();
  delay(2000);
}
