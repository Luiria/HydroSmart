#ifndef LEDBARGRAPH_H
#define LEDBARGRAPH_H

class LedBarGraph
{
private:
    int *ledPins;
    int size;

public:
    LedBarGraph(int ledPins[], int size = 10);
    void begin();
    void initLed();
    void update(int level);
};

#endif