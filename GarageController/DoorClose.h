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
	DoorClose();
	void entryAction();
	void exitAction();
	string getStatusId();

};

#endif /* DOORCLOSE_H_ */
