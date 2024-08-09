#pragma once

class LedView
{
private:
    int _pinRed;
    int _pinGreen;
    int _pinYellow;
    void disableAll();
public:
    LedView(int red, int green, int yellow);
    ~LedView();
    void red();
    void green();
    void yellow();
    void enableAll();
    void showLoadAnimation();
    void showShortAnimation();
};