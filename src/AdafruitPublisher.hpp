#include <Arduino.h>
#include <AdafruitIO_WiFi.h>

#include "IDataPublisher.hpp"

class AdafruitPublisher : public IDataPublisher
{

private:
    const char *username;
    const char *key;
    const char *ssid;
    const char *pass;

    AdafruitIO_WiFi *io;
    AdafruitIO_Feed *temperature;
    AdafruitIO_Feed *humidity;

public:
    AdafruitPublisher(const char *username, const char *key, const char *ssid, const char *pass);
    void begin() override;
    void run() override;
    void sendData(const char *feedName, float value) override;
};