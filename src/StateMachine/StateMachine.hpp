#include <Devices.h>
#include <View.h>

class StateMachine
{
private:
    enum
    {
        Work = 0,
        ReadLock = 1,
        ReadOpen = 2
    } _currentState;

    ServoContainer *_servo;
    LedView *_view;
    ResisterChanger *_resister;
    int _lastReadState = 0;

    void readOpenTick();
    void readLockTick();

    void enableWorkState();
    void enableReadLockState();
    void enableReadOpenState();
    void workTick();
    void start();

public:
    StateMachine(LedView *view);
    ~StateMachine();
    void nextState();
    void tickState();
};