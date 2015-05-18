/*
 * LEDControl.h
 *
 *  Created on: May 18, 2015
 *      Author: ajm5774
 */

#ifndef LEDCONTROL_H_
#define LEDCONTROL_H_

#include "StateContext.h"
#include "Control.h"


class LEDControl: public Control
{
public:

//====inherited
	//variables
	StateContext * context;

	//functions
	LEDControl();
	LEDControl(StateContext * context);
	virtual void run();

//====other
	//functions
	void setWheelRot(bool wheelRot);



private:
	Interrupt timer;
	bool wheelRotated;
	mutex wheelRotLock;
};

#endif /* LEDCONTROL_H_ */
