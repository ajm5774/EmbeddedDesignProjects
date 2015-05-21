/*
 * InterruptControl.h
 *
 *  Created on: May 18, 2015
 *      Author: ajm5774
 */

#ifndef INTERRUPTCONTROL_H_
#define INTERRUPTCONTROL_H_

#include "StateContext.h"
#include "StateEvents.h"
#include "Control.h"
#include "LEDControl.h"
#include "Timer.h"
#include <stdio.h>
#include <sys/neutrino.h>
#include <hw/inout.h>



const struct sigevent * interruptReceived(void *arg, int id);

class InterruptControl: public Control
{
public:

//====inherited
	//variables
	StateContext * context;

	//functions
	InterruptControl();
	InterruptControl(StateContext * context);
	virtual void run();

//====other
	//functions
	int getCount();
	void updateCount();

	//variables
	StateEvent event;

private:
	Interrupt timer;
	int waitTimeMicros;
	int _pulseCount;
	int _pulseHist;
	int _interruptID;
	uint8_t input;
	uint8_t lastInput;

	bool awaitingReset;
	bool awaitingResetVals;
	int waitCount;
	int modeHeldWaitCount;

	bool isButton1Pressed(uint8_t input);
	bool isButton2Pressed(uint8_t input);
	bool isButton3Pressed(uint8_t input);

	bool button1BeenPressed(uint8_t lastInput);
	bool button2BeenPressed(uint8_t lastInput);
	bool button3BeenPressed(uint8_t lastInput);
};

#endif /* INTERRUPTCONTROL_H_ */
