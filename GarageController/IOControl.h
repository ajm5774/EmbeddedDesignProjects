/*
 * IOControl.h
 *
 *  Created on: Mar 6, 2015
 *      Author: ajm5774
 */

#ifndef IOCONTROL_H_
#define IOCONTROL_H_

#include "StateContext.h"
#include "Control.h"

class IOControl: public Control
{
public:
	StateContext context;
	IOControl();
	IOControl(StateContext context);
	virtual void run();
};

int getChar();

#endif /* IOCONTROL_H_ */
