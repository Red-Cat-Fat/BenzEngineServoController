
#include <header.hpp>
#include <defines.hpp>

Button _controlButton(BUTTON_STATE_PIN);
LedView *_view;
CloseWorkStateMachine* _stateMachine;

void setup()
{
  pinMode(READ_LOC_PIN, INPUT);
  _view = new LedView(RED_LED, GREEN_LED, YELLOW_LED);
  _view->showLoadAnimation();
  _stateMachine = new CloseWorkStateMachine(_view);
}

void loop()
{
  _controlButton.tick();

  if (_controlButton.click())
    _stateMachine->nextState();

  _stateMachine->tick();
}