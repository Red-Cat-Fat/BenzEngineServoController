#pragma once
#include <ServoSmooth.h>

class ServoContainer
{
private:
    int _angleClose;
    int _angleOpen;
    int _stepAngle;
    int _targetAngle;
    ServoSmooth *_servo;
    void setNewAngle(int angle);
 
public:
    ServoContainer(
        int pin,
        int defaultClose,
        int defaultOpen,
        int speed = 50,
        double accel = 0.3,
        int stepChange = 3);
    ~ServoContainer();
    void open();
    void close();
    void setOpen(int value);
    void setClose(int value);
    void setAngle(int angle);
    void tick();
};