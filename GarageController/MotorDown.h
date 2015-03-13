/*
 * MotorDown.h
 *
 *  Created on: Mar 6, 2015
 *      Author: ajm5774
 */

#ifndef MOTORDOWN_H_
#define MOTORDOWN_H_
#include "State.h"

class MotorDown: public State
{
public:
	string statusId;
	MotorDown();
	void entryAction();
	void exitAction();
	void activity();
};

#endif /* MOTORDOWN_H_ */
