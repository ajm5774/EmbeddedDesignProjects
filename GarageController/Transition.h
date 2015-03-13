/*
 * Transition.h
 *
 *  Created on: Mar 6, 2015
 *      Author: ajm5774, xxz1530
 */

#ifndef TRANSITION_H_
#define TRANSITION_H_
#include "State.h"
#include "StateEvents.h"

class Transition
{

public:

	State * nextState;
	State * currentState;
	StateEvent triggerEvent;


	Transition(State * currState, State * nextState, StateEvent trigEvent);
	bool guard();
	void addGuard(bool (*f)());
};

#endif /* TRANSITION_H_ */
