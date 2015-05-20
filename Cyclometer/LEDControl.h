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
#include "Timer.h"
#include <stdio.h>


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
	static bool wheelRotated;
	static bool isAutoMode;
	static bool wheelRotatedCleared;

	//functions
	void setWheelRot(bool wheelRot);
	void setAutoMode(bool isAutoMode);


private:
	Interrupt timer;

	pthread_mutex_t wheelRotLock;
};

#endif /* LEDCONTROL_H_ */
