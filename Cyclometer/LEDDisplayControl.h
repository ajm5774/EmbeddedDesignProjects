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
#include <stdio.h>
#include <unistd.h>
#include "Timer.h"
#include "Modes.h"

#define NUMSEGS 4



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
	static uint8_t segValues[];
	Mode displayMode;

private:
	Interrupt timer;
	uint8_t ConvertIntToDisplay(uint8_t digit);
};

#endif /* LEDDISPLAYCONTROL_H_ */
