#include "CloseWorkStateMachine.hpp"
#include <Arduino.h>
#include <defines.hpp>

CloseWorkStateMachine::CloseWorkStateMachine(LedView *view)
{
    _view = view;
    _lockTrigger = new LockTrigger(READ_LOC_PIN, LOW, 3);
    _servo = new ServoContainer(SERVO_PIN, 0, 0);
    _resister = new ResisterChanger(POTENSIOMETER_PIN, 0, 180);
    start();
}

CloseWorkStateMachine::~CloseWorkStateMachine()
{
}

void CloseWorkStateMachine::readCloseTick()
{
    _servo->setClose(_resister->getValue());
}

void CloseWorkStateMachine::workTick()
{
    _servo->setAngle(_resister->getValue());
    _lockTrigger->tick();

    if (_lockTrigger->isCloseTriggerEnter())
        setState(Close);

    _lockTrigger->clearTriggers();
}

void CloseWorkStateMachine::closeTick()
{
    _lockTrigger->tick();
    if (_lockTrigger->isOpenTriggerEnter())
        setState(Work);

    _lockTrigger->clearTriggers();
}

void CloseWorkStateMachine::start()
{
    setState(Wait);
    _servo->close();
    _view->enableAll();
}

void CloseWorkStateMachine::setState(State newState)
{
    if (newState != Wait && _currentState == newState)
        return;
    _lastState = _currentState;
    _currentState = newState;

    switch (newState)
    {
    case Wait:
        _lastState = Work;
        break;
    case Work:
        _view->green();
        break;
    case ReadLock:
        _view->yellow();
        break;
    case Close:
        _view->red();
        _servo->close();
        break;
    default:
        break;
    }
}

void CloseWorkStateMachine::nextState()
{
    if (_currentState == Wait)
    {
        setState(Work);
        return;
    }

    if (_currentState == ReadLock)
    {
        setState(_lastState);
        return;
    }

    if (_currentState == Work || _currentState == Close)
    {
        setState(ReadLock);
        return;
    }
}

void CloseWorkStateMachine::tick()
{
    _servo->tick();

    switch (_currentState)
    {
    case Wait:
        break;
    case Work:
        workTick();
        break;
    case ReadLock:
        readCloseTick();
        break;
    case Close:
        closeTick();
        break;
    }
}
