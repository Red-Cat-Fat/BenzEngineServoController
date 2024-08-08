
#include <header.h>
#include <defines.h>

Button _controlButton(BUTTON_STATE_PIN);
StateMachine *_stateMachine;
LedView *_view;

void setup()
{
  pinMode(READ_LOC_PIN, INPUT);
  _view = new LedView(RED_LED, GREEN_LED, YELLOW_LED);
  _view->showLoadAnimation();
  _stateMachine = new StateMachine(_view);
}

void loop()
{
  _controlButton.tick();

  if (_controlButton.click())
    _stateMachine->nextState();

  _stateMachine->tickState();
}