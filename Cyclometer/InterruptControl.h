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
#include "CalculationControl.h"
#include "Cyclometer.h"
#include "Timer.h"
#include <stdio.h>
#include <sys/neutrino.h>
#include <sys/mman.h>
#include <hw/inout.h>

#define DAQ_BASE 0x280

//interrupt clear
#define DAQ_CLEAR  			DAQ_BASE + 0
#define CLEAR          		0x02
#define DIO_IRQ        		0x05

//interrupt control
#define DAQ_INTER_CTRL  	DAQ_BASE + 4
#define INIT_BIT       		0x02

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
	static uintptr_t interCtrlHandle;
	static uintptr_t clearHandle;

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
	bool b3Triggered;

	bool isButton1Pressed(uint8_t input);
	bool isButton2Pressed(uint8_t input);
	bool isButton3Pressed(uint8_t input);

	bool button1BeenPressed(uint8_t lastInput);
	bool button2BeenPressed(uint8_t lastInput);
	bool button3BeenPressed(uint8_t lastInput);
};

#endif /* INTERRUPTCONTROL_H_ */
