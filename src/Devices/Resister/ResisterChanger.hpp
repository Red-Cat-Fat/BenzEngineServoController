class ResisterChanger
{
private:
    int _pinRead;
    int _minValue;
    int _maxValue;

public:
    ResisterChanger(int pin, int minValue, int maxValue);
    ~ResisterChanger();
    int getValue();
};
