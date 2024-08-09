#include <Devices.hpp>
#include <View.hpp>

class OpenCloseWorkStateMachine
{
private:
    enum
    {
        Work = 0,
        ReadLock = 1,
        ReadOpen = 2
    } _currentState;

    LedView *_view;
    ServoContainer *_servo;
    ResisterChanger *_resister;
    int _lastReadState = 0;

    void readOpenTick();
    void readCloseTick();

    void enableWorkState();
    void enableReadLockState();
    void enableReadOpenState();
    void workTick();
    void start();

public:
    OpenCloseWorkStateMachine(LedView *view);
    ~OpenCloseWorkStateMachine();
    void nextState();
    void tick();
};