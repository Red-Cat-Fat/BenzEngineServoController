#include <Devices/Servo/ServoContainer.hpp>

ServoContainer::ServoContainer(int pin, int defaultClose, int defaultOpen, int speed, double accel)
{
    _angleOpen = defaultOpen;
    _angleClose = defaultClose;
    _servo = new ServoSmooth();
    _servo -> attach(pin, 600, 2400);
    _servo -> setSpeed(speed);
    _servo -> setAccel(accel);
}

ServoContainer::~ServoContainer()
{
}

void ServoContainer::open()
{
    _servo -> setTargetDeg(_angleOpen);
}

void ServoContainer::close()
{
    _servo -> setTargetDeg(_angleClose);
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

void ServoContainer::tick()
{
    _servo -> tick();
}
