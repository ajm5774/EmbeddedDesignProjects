/*
 * OvercurrentControl.h
 *
 *  Created on: Mar 6, 2015
 *      Author: ajm5774
 */

#ifndef OVERCURRENTCONTROL_H_
#define OVERCURRENTCONTROL_H_

#include "Control.h"
#include "Timer.h"
#include <sys/neutrino.h>

class OverCurrentControl: public Control
{
public:
	StateContext * context;
	OverCurrentControl();
	OverCurrentControl(StateContext * context);
	virtual void run();

private:
	Interrupt timer;
};

#endif /* OVERCURRENTCONTROL_H_ */
