/*
 * OvercurrentControl.h
 *
 *  Created on: Mar 6, 2015
 *      Author: ajm5774
 */

#ifndef OVERCURRENTCONTROL_H_
#define OVERCURRENTCONTROL_H_

#include "Control.h"

class OverCurrentControl: public Control
{
public:
	StateContext context;
	OverCurrentControl();
	OverCurrentControl(StateContext context);
	virtual void run();
};

#endif /* OVERCURRENTCONTROL_H_ */
