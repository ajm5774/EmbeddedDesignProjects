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
#include "ConcurrentQueue.h"
#include "QueueItem.h"
#include "DoorClose.h"
#include "DoorOpen.h"
#include "DoorStop.h"
#include "MotorUp.h"
#include "MotorDown.h"


class StateContext
{
	State * currentState;
	State * previousState;
	std::map<State, Transition> stateTransitions;

	// creating the states
	DoorOpen dooropen;
	DoorClose doorclose;
	DoorStop doorstop;
	MotorUp motorup;
	MotorDown motordown;

public:
	StateContext();
	void queueEvent(StateEvent event);

private:
	ConcurrentQueue queue;
	void accept(StateEvent event);
};

#endif /* STATECONTEXT_H_ */
