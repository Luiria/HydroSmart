#include <Arduino.h>

#include "humidity.h"

#include "DHTesp.h"
#include <WiFi.h>
#include <WebServer.h>      

#include "AdafruitIO_WiFi.h"   



void setup()
{
  initDHT();
}

void loop()
{
  readHumidity();
  delay(2000);
}
