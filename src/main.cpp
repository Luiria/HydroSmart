#include <Arduino.h>

#include "./hal/UltraSonicSensor.hpp"
#include "./hal/LedBarGraph.hpp"
#include "./app/TankController.hpp"

int ledPins[] = {0, 4, 16, 17, 5, 18, 19, 21, 22, 23};

UltraSonicSensor ultraSonicSensor(27, 26);
LedBarGraph ledBarGraph(ledPins);

TankController tankController(ultraSonicSensor, ledBarGraph);

void setup()
{
  Serial.begin(115200);
  Serial.println();

  ultraSonicSensor.begin();
  ledBarGraph.begin();
  ledBarGraph.initLed();
}

void loop()
{
  tankController.update();
  delay(5000);
}