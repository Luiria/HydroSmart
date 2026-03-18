#include "UltraSonicSensor.hpp"

UltraSonicSensor::UltraSonicSensor(uint8_t triggerPin, uint8_t echoPin)
    : triggerPin(triggerPin), echoPin(echoPin) {}

void UltraSonicSensor::begin()
{
    pinMode(this->triggerPin, OUTPUT);
    pinMode(this->echoPin, INPUT);
}

void UltraSonicSensor::read()
{
    // Clears the trigPin
    digitalWrite(this->triggerPin, LOW);
    delayMicroseconds(2);

    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(this->triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(this->triggerPin, LOW);

    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(this->echoPin, HIGH);

    // Calculating the distance
    distance = duration * 0.034 / 2;

    this->setLevel();
}

void UltraSonicSensor::setTankHeight(int minDistance, int maxDistance)
{
    this->tankMinDistance = minDistance;
    this->tankMaxDistance = maxDistance;
};

void UltraSonicSensor::setLevel()
{
    if (distance <= tankMinDistance)
        level = 100;
    else if (distance >= tankMaxDistance)
        level = 0;
    else
        // calul %
        level = map(distance, tankMaxDistance, tankMinDistance, 0, 100);

}