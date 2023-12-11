#include <msp430.h>
#include "libTimer.h"
#include "stateMachine.h"
#include "sr.h"
#include "toy.h"

#define BUTTONS (BUTTON1 | BUTTON2 | BUTTON3 | BUTTON4)



void configureToy() {

  configureClocks();

  enableWDTInterrupts();



  P1DIR |= LED_RED | LED_GREEN;

  P2DIR |= SPEAKER;



  P2REN |= BUTTONS;

  P2IE |= BUTTONS;

  P2IES |= BUTTONS;

  P2IFG &= ~BUTTONS;



  or_sr(0x18);  // Enter LPM0 with interrupts enabled

}



void turnOnLEDs(int leds) {

  P1OUT |= leds;

}



void turnOffLEDs() {

  P1OUT &= ~(LED_RED | LED_GREEN);

}



void playSound() {

  P2OUT |= SPEAKER;

}



void stopSound() {

  P2OUT &= ~SPEAKER;

}



void handleButtonPresses() {

  if (P2IFG & BUTTON1) {

    currentState = STATE_BLINK;

  } else if (P2IFG & BUTTON2) {

    currentState = STATE_BUZZ;

  } else if (P2IFG & BUTTON3) {

    currentState = STATE_DIM;

  } else if (P2IFG & BUTTON4) {

    currentState = STATE_OFF;

  }



  P2IFG &= ~BUTTONS;  // Clear button interrupt flags

  transitionState();  // Call the transitionState function

}
