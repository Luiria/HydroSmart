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
        delay(500);
    }

    for (int i = 0; i < this->size; i++)
        digitalWrite(ledPins[i], LOW);
}

void LedBarGraph::update(int level)
{
    int NumberOfLedToLight = level * 0.1;

    for (int i = 0; i < this->size; i++)
    {
        if (i < NumberOfLedToLight)
            digitalWrite(this->ledPins[i], HIGH);
        else
            digitalWrite(this->ledPins[i], LOW);
    }
}