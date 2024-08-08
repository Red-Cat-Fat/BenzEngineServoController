#include "StateMachine.hpp"
#include <Arduino.h>
#include <defines.h>

StateMachine::StateMachine(LedView *view)
{
    _view = view;
    _servo = new ServoContainer(SERVO_PIN, 90, 90);
    _resister = new ResisterChanger(POTENSIOMETER_PIN, 0, 180);
    start();
}

StateMachine::~StateMachine()
{
}

void StateMachine::workTick()
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
void StateMachine::readOpenTick()
{
    _servo->setOpen(_resister->getValue());
}

void StateMachine::readLockTick()
{
    _servo->setClose(_resister->getValue());
}

void StateMachine::nextState()
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

void StateMachine::tickState()
{
    _servo->tick();
    switch (_currentState)
    {
    case Work:
        workTick();
        break;
    case ReadLock:
        readLockTick();
        break;
    case ReadOpen:
        readOpenTick();
        break;
    }
}

void StateMachine::start()
{
    enableWorkState();
}

void StateMachine::enableWorkState()
{
    _currentState = Work;
    _view->green();
}

void StateMachine::enableReadLockState()
{
    _currentState = ReadLock;
    _view->red();
}

void StateMachine::enableReadOpenState()
{
    _currentState = ReadOpen;
    _view->yellow();
}
