#include <Devices.hpp>
#include <Arduino.h>
#include "LockTrigger.hpp"

LockTrigger::LockTrigger(
    int pinLockWait,
    int openState = LOW,
    int tickChangeCountMaxSize = 5)
{
    _pinLockWait = pinLockWait;
    _openState = openState;
    _tickChangeCountMaxSize = tickChangeCountMaxSize;
    _tickChangeCount = 0;
    _lastState = readCurrentState();
    clearTriggers();
}

LockTrigger::~LockTrigger()
{
}

bool LockTrigger::isOpenTriggerEnter()
{
    return _triggerOpen;
}

bool LockTrigger::isCloseTriggerEnter()
{
    return _triggerClose;
}

void LockTrigger::clearTriggers()
{
    _triggerOpen = false;
    _triggerClose = false;
}

void LockTrigger::onChangeState(int newState)
{
    _lastState = newState;
    if (newState == _openState)
        _triggerOpen = true;
    else
        _triggerClose = true;
}

void LockTrigger::tick()
{
    int currentState = readCurrentState();
    if (currentState != _lastState)
    {
        _tickChangeCount++;
        if (_tickChangeCount >= _tickChangeCountMaxSize)
            onChangeState(currentState);
    }
    else
    {
        if (_tickChangeCount != 0)
            _tickChangeCount = 0;
    }
}

int LockTrigger::readCurrentState()
{
    return digitalRead(_pinLockWait);
}
