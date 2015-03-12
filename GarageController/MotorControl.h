/*
 * MotorControl.h
 *
 *  Created on: Mar 6, 2015
 *      Author: ajm5774
 */

#ifndef MOTORCONTROL_H_
#define MOTORCONTROL_H_

class MotorControl: public Control
{
	bool motorUp = false;
	bool motorDown = false;

private:
	void doorClose();
	void doorOpen();
};

#endif /* MOTORCONTROL_H_ */
