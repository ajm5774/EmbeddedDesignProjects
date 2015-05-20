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
	static void setWheelRot(bool wheelRot);
	static void setAutoMode(bool isAutoMode);


private:
	Interrupt timer;
	static bool wheelRotated;
	static bool isAutoMode;
	static bool wheelRotatedCleared;
	pthread_mutex_t wheelRotLock;
};

#endif /* LEDCONTROL_H_ */
