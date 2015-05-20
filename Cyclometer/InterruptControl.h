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
#include "Timer.h"
#include <stdio.h>
#include <sys/neutrino.h>



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
	int _pulseCount;
	int _pulseHist;
	int _interruptID;

};

#endif /* INTERRUPTCONTROL_H_ */
