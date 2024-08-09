#include <View/LedView.hpp>
#include <Arduino.h>
#include "LedView.hpp"

LedView::LedView(int red, int green, int yellow)
{
    _pinRed = red;
    _pinGreen = green;
    _pinYellow = yellow;

    pinMode(_pinRed, OUTPUT);
    pinMode(_pinGreen, OUTPUT);
    pinMode(_pinYellow, OUTPUT);
}

LedView::~LedView()
{
    disableAll();
}

void LedView::red()
{
    disableAll();
    digitalWrite(_pinRed, HIGH);
}

void LedView::green()
{
    disableAll();
    digitalWrite(_pinGreen, HIGH);
}

void LedView::yellow()
{
    disableAll();
    digitalWrite(_pinYellow, HIGH);
}

void LedView::enableAll()
{
    digitalWrite(_pinRed, HIGH);
    digitalWrite(_pinGreen, HIGH);
    digitalWrite(_pinYellow, HIGH);
}
void LedView::disableAll()
{
    digitalWrite(_pinRed, LOW);
    digitalWrite(_pinGreen, LOW);
    digitalWrite(_pinYellow, LOW);
}

void LedView::showLoadAnimation()
{
    int step = 0;
    while (step < 9)
    {
        disableAll();
        int index = -1;
        switch (step % 3)
        {
        case 0:
            index = _pinYellow;
            break;
        case 1:
            index = _pinRed;
            break;
        case 2:
            index = _pinGreen;
            break;
        }
        if (index >= 0)
            digitalWrite(index, HIGH);
        delay(100);
        step++;
    }
    disableAll();
}


void LedView::showShortAnimation()
{
    int step = 0;
    while (step < 3)
    {
        disableAll();
        int index = -1;
        switch (step % 3)
        {
        case 0:
            index = _pinYellow;
            break;
        case 1:
            index = _pinRed;
            break;
        case 2:
            index = _pinGreen;
            break;
        }
        if (index >= 0)
            digitalWrite(index, HIGH);
        delay(100);
        step++;
    }
    disableAll();
}
