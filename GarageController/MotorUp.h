/*
 * MotorUp.h
 *
 *  Created on: Mar 6, 2015
 *      Author: ajm5774
 */

#ifndef MOTORUP_H_
#define MOTORUP_H_
#include "State.h"

class MotorUp: public State
{
public:
	string statusId;
	MotorUp();
	void entryAction();
	void exitAction();
	void activity();
};


#endif /* MOTORUP_H_ */
