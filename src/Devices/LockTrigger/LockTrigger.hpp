#pragma once

class LockTrigger
{
private:
    int _pinLockWait;
    int _lastState;
    int _openState;
    int _tickChangeCount;
    int _tickChangeCountMaxSize;

    bool _triggerOpen;
    bool _triggerClose;

    void onChangeState(int newState);
    int readCurrentState();

public:
    LockTrigger(
        int pinLockWait,
        int openState,
        int tickChangeCountMaxSize);
    ~LockTrigger();
    void tick();
    bool isOpenTriggerEnter();
    bool isCloseTriggerEnter();
    void clearTriggers();
};