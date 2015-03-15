/*
 * MotorControl.h
 *
 *  Created on: Mar 6, 2015
 *      Author: ajm5774
 */

#ifndef MOTORCONTROL_H_
#define MOTORCONTROL_H_

#include "Control.h"
#include "StateContext.h"
#include "Timer.h"
#include <sys/neutrino.h>

class MotorControl: public Control
{
public:
	static bool motorUp;
	static bool motorDown;
	StateContext * context;
	MotorControl();
	MotorControl(StateContext * context);
	virtual void run();

private:
	Interrupt timer;
	void doorClose();
	void doorOpen();
};

#endif /* MOTORCONTROL_H_ */
