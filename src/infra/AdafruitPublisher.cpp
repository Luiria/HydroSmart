#include "AdafruitPublisher.hpp"

AdafruitPublisher::AdafruitPublisher(const  char *username, const char *key, const char *ssid, const char *pass)
    : username(username), key(key), ssid(ssid), pass(pass)
{
    io = new AdafruitIO_WiFi(username, key, ssid, pass);
};

void AdafruitPublisher::begin()
{
    Serial.print("connexion à Adafruit IO...");
    io->connect();

    while (io->status() < AIO_CONNECTED)
    {
        Serial.print(".");
        delay(500);
    }

    Serial.println("Connecté !");
};

void AdafruitPublisher::run()
{
    io->run();
};

void AdafruitPublisher::sendData(const char *feedName, float value)
{
    AdafruitIO_Feed *feed = io->feed(feedName);
    if (feed)
        feed->save(value);
}

bool AdafruitPublisher::isConnected(){
    return this->io->status() >= AIO_CONNECTED;
}