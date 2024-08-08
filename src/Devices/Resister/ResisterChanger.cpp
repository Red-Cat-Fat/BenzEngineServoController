#include <Arduino.h>
#include <Devices/Resister/ResisterChanger.hpp>

ResisterChanger::ResisterChanger(int pin, int minValue = 0, int maxValue = 1023)
{
    _pinRead = pin;
    _minValue = minValue;
    _maxValue = maxValue;
}

ResisterChanger::~ResisterChanger()
{
}

int ResisterChanger::getValue()
{
    return map(analogRead(_pinRead), 0, 1023, _minValue, _maxValue);
}