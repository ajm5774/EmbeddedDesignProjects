/*
 * DoorStop.h
 *
 *  Created on: Mar 6, 2015
 *      Author: ajm5774
 */

#ifndef DOORSTOP_H_
#define DOORSTOP_H_
#include "State.h"

class DoorStop: public State
{
public:
	DoorStop();
	void entryAction();
	void exitAction();
	string getStatusId();
};

#endif /* DOORSTOP_H_ */
