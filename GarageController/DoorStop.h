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
	string statusId;
	DoorStop();
	void entryAction();
	void exitAction();

};

#endif /* DOORSTOP_H_ */
