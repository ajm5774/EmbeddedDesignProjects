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

	StateEvent triggerEvent;
	State * nextState;
	State * currentState;
	State * prevState;

	Transition(State * cState, State *nState, StateEvent sEvent);
	bool guard();
	void addGuard(State * pState);
	StateEvent getTriggerEvent();
};

#endif /* TRANSITION_H_ */
