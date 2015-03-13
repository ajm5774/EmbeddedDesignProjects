/*
 * MotorControl.h
 *
 *  Created on: Mar 6, 2015
 *      Author: ajm5774
 */

#ifndef MOTORCONTROL_H_
#define MOTORCONTROL_H_

#include "Control.h"

class MotorControl: public Control
{
public:
	bool motorUp;
	bool motorDown;

private:
	void doorClose();
	void doorOpen();
};

#endif /* MOTORCONTROL_H_ */
