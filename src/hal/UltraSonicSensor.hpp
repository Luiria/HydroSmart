#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H

#include <Arduino.h>

class UltraSonicSensor
{
private:
    uint8_t triggerPin;
    uint8_t echoPin;
    long duration;
    int distance;
    int level;

    int tankMinDistance;
    int tankMaxDistance;

public:
    UltraSonicSensor(uint8_t triggerPin, uint8_t echoPin);
    void begin();
    void read();

    // GETTERS
    int getLevel() { return this->level; }
    int getDistance() { return this->distance; }
    int getDuration() { return this->duration; }

    // SETTERS
    void setLevel();
    void setTankHeight(int minDistance, int maxDistance);

};

#endif