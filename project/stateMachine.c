#include "toy.h"
#include "stateMachine.h"



void transitionState() {

  switch (currentState) {
  case STATE_OFF:

    turnOffLEDs();

    stopSound();

    break;

  case STATE_BLINK:

    turnOnLEDs(LED_RED);

    stopSound();

    break;

  case STATE_BUZZ:

    turnOffLEDs();

    playSound();

    break;
  case STATE_DIM:

    // Example logic for STATE_DIM transition

    turnOnLEDs(LED_RED | LED_GREEN);

    __delay_cycles(100000);  // Dimming effect

    turnOffLEDs();

    __delay_cycles(100000);
    break;
  default:
    break;
  }
}
