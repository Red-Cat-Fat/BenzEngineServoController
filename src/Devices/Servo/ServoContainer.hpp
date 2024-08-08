#include <ServoSmooth.h>

class ServoContainer
{
private:
    int _angleClose;
    int _angleOpen;
    ServoSmooth* _servo;

public:
    ServoContainer(int pin, int defaultClose, int defaultOpen, int speed = 50, double accel = 0.3);
    ~ServoContainer();
    void open();
    void close();
    void setOpen(int value);
    void setClose(int value);
    void tick();
};