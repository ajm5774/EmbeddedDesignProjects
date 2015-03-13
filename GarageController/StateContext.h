/*
 * StateContext.h
 *
 *  Created on: Mar 6, 2015
 *      Author: ajm5774
 */

#ifndef STATECONTEXT_H_
#define STATECONTEXT_H_

#include "State.h"
#include "StateEvents.h"
#include <map>
#include "Transition.h"

class StateContext
{
	State * currentState;
	State * previousState;
	std::map<State, Transition[]> stateTransitions;

public:
	StateContext();
	void queueEvent(StateEvent event);

private:
	void accept(StateEvent event);
};

#endif /* STATECONTEXT_H_ */
