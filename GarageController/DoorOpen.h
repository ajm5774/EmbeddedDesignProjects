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
	string statusId;
	DoorOpen();
	void entryAction();
	void exitAction();

};

#endif /* DOOROPEN_H_ */
