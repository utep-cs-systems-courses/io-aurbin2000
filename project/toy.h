#ifndef toy_included
#define toy_included

#include <msp430.h>
#include "libTimer.h"

#define LED_RED BIT0
#define LED_GREEN BIT6
#define SPEAKER BIT7
#define BUTTON1 BIT0
#define BUTTON2 BIT1
#define BUTTON3 BIT2
#define BUTTON4 BIT3

enum State {

  STATE_OFF,

  STATE_BLINK,

  STATE_BUZZ,

      STATE_DIM

};

extern volatile enum State currentState;

void configureToy();
void turnOnLEDs(int leds);
void turnOffLEDs();
void playSound();
void stopSound();
void transitionState();
void disableWDTInterrupts();

#endif // toy_included
