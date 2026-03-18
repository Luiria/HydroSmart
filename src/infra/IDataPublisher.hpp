#ifndef IDATAPUBLISHER_H
#define IDATAPUBLISHER_H

class IDataPublisher
{
public:
    virtual void begin() = 0;
    virtual void run() = 0;
    virtual void sendData(const char *feedName, float value) = 0;
    virtual bool isConnected() = 0;
    virtual ~IDataPublisher() {}
};

#endif