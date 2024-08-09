#pragma once
#include <header.hpp>

class CloseWorkStateMachine
{
private:
    enum State
    {
        Wait = 0,
        Work = 1,
        ReadLock = 2,
        Close = 3
    } _currentState;

    State _lastState;
    LockTrigger *_lockTrigger;
    LedView *_view;
    ServoContainer *_servo;
    ResisterChanger *_resister;

    void readCloseTick();
    void workTick();
    void closeTick();
    void start();

    void setState(State newState);

public:
    CloseWorkStateMachine(LedView *view);
    ~CloseWorkStateMachine();
    void nextState();
    void tick();
};