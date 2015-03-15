/*
 * DoorOpen.h
 *
 *  Created on: Mar 6, 2015
 *      Author: ajm5774
 */

#ifndef DOOROPEN_H_
#define DOOROPEN_H_
#include "State.h"

class DoorOpen: public State
{
public:
	DoorOpen();
	void entryAction();
	void exitAction();
	string getStatusId();
};

#endif /* DOOROPEN_H_ */
