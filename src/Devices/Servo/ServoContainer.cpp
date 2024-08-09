#include <Devices/Servo/ServoContainer.hpp>
#include "ServoContainer.hpp"

ServoContainer::ServoContainer(
    int pin,
    int defaultClose,
    int defaultOpen,
    int speed,
    double accel,
    int stepChange)
{
    _angleOpen = defaultOpen;
    _angleClose = defaultClose;
    _stepAngle = stepChange;
    _targetAngle = _angleClose;
    _servo = new ServoSmooth();
    _servo->attach(pin, 600, 2400);
    _servo->setSpeed(speed);
    _servo->setAccel(accel);
}

ServoContainer::~ServoContainer()
{
}

void ServoContainer::open()
{
    setNewAngle(_angleOpen);
}

void ServoContainer::close()
{
    setNewAngle(_angleClose);
}

void ServoContainer::setOpen(int value)
{
    _angleOpen = value;
    open();
}

void ServoContainer::setClose(int value)
{
    _angleClose = value;
    close();
}

void ServoContainer::setAngle(int angle)
{
    setNewAngle(angle);
}

void ServoContainer::tick()
{
    _servo->tick();
}

void ServoContainer::setNewAngle(int angle)
{
    if (abs(angle - _targetAngle) < _stepAngle)
       return;
    _servo->setTargetDeg(angle);
    _targetAngle = angle;
}