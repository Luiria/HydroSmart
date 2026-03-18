#include <Arduino.h>

#include "./hal/UltraSonicSensor.hpp"
#include "./hal/LedBarGraph.hpp"

int ledPins[] = {0, 4, 16, 17, 5, 18, 19, 21, 22, 23};

UltraSonicSensor sonicSensor(27, 26);
LedBarGraph ledBarGraph(ledPins);

void setup()
{
  Serial.begin(115200);
  Serial.println();

  sonicSensor.begin();
  ledBarGraph.begin();
  ledBarGraph.initLed();
}

void loop()
{
  sonicSensor.read();
  delay(5000);
}