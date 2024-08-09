#include "OpenCloseWorkStateMachine.hpp"
#include <Arduino.h>
#include <defines.hpp>

OpenCloseWorkStateMachine::OpenCloseWorkStateMachine(LedView *view)
{
    _view = view;
    _servo = new ServoContainer(SERVO_PIN, 90, 90);
    _resister = new ResisterChanger(POTENSIOMETER_PIN, 0, 180);
    start();
}

OpenCloseWorkStateMachine::~OpenCloseWorkStateMachine()
{
}

void OpenCloseWorkStateMachine::workTick()
{
    int newState = digitalRead(READ_LOC_PIN);
    if (_lastReadState != newState)
    {
        _lastReadState = newState;
        if (_lastReadState == HIGH)
            _servo->close();
        else
            _servo->open();
    }
}
void OpenCloseWorkStateMachine::readOpenTick()
{
    _servo->setOpen(_resister->getValue());
}

void OpenCloseWorkStateMachine::readCloseTick()
{
    _servo->setClose(_resister->getValue());
}

void OpenCloseWorkStateMachine::nextState()
{
    switch (_currentState)
    {
    case Work:
        enableReadLockState();
        break;
    case ReadLock:
        enableReadOpenState();
        break;
    case ReadOpen:
        enableWorkState();
        break;
    }
}

void OpenCloseWorkStateMachine::tick()
{
    _servo->tick();
    switch (_currentState)
    {
    case Work:
        workTick();
        break;
    case ReadLock:
        readCloseTick();
        break;
    case ReadOpen:
        readOpenTick();
        break;
    }
}

void OpenCloseWorkStateMachine::start()
{
    enableWorkState();
}

void OpenCloseWorkStateMachine::enableWorkState()
{
    _currentState = Work;
    _view->green();
}

void OpenCloseWorkStateMachine::enableReadLockState()
{
    _currentState = ReadLock;
    _view->red();
}

void OpenCloseWorkStateMachine::enableReadOpenState()
{
    _currentState = ReadOpen;
    _view->yellow();
}
