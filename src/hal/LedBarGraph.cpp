#include <Arduino.h>

#include "LedBarGraph.hpp"

LedBarGraph::LedBarGraph(int ledPins[], int size) : ledPins(ledPins), size(size) {};

void LedBarGraph::begin()
{
    for (int i = 0; i < this->size; i++)
    {
        pinMode(ledPins[i], OUTPUT);
    }
}

void LedBarGraph::initLed()
{
    for (int i = 0; i < this->size; i++)
    {
        digitalWrite(ledPins[i], HIGH);
        delay(1000);
    }

    for (int i = 0; i < this->size; i++)
        digitalWrite(ledPins[i], LOW);
}