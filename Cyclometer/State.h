/*
 * State.h
 *
 *  Created on: Mar 6, 2015
 *      Author: ajm5774
 */

#ifndef STATE_H_
#define STATE_H_

#include "StateEvents.h"

class State
{
public:
	State();
	virtual void entryAction();
	virtual void exitAction();
	virtual State* accept(StateEvent ev);
};

#endif /* STATE_H_ */
