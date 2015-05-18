/*
 * LEDDisplayControl.h
 *
 *  Created on: May 18, 2015
 *      Author: ajm5774
 */

#ifndef LEDDISPLAYCONTROL_H_
#define LEDDISPLAYCONTROL_H_

#include "StateContext.h"
#include "Control.h"


class LEDDisplayControl: public Control
{
public:

//====inherited
	//variables
	StateContext * context;

	//functions
	LEDDisplayControl();
	LEDDisplayControl(StateContext * context);
	virtual void run();

//====other
	//variables
	int seg1Value;
	int seg2Value;
	int seg3Value;
	int seg4Value;

	Mode displayMode;

private:
	Interrupt timer;
};

#endif /* LEDDISPLAYCONTROL_H_ */
