/*
 * DoorClose.h
 *
 *  Created on: Mar 6, 2015
 *      Author: ajm5774
 */

#ifndef DOORCLOSE_H_
#define DOORCLOSE_H_
#include "State.h"

class DoorClose: public State
{
public:
	string statusId;
	DoorClose();
	void entryAction();
	void exitAction();

};

#endif /* DOORCLOSE_H_ */
