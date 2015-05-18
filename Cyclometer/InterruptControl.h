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
	//variables
	uint8_t input = 0;
	uint8_t lastInput = 0;
	StateEvent event;

	//functions
	void handleModePressed();
	void handleSetPressed();
	void handleMagSensorTriggered();

private:
	Interrupt timer;

};

#endif /* INTERRUPTCONTROL_H_ */
