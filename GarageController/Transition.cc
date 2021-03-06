/*
 * Transition.cc
 *
 *  Created on: Mar 13, 2015
 *      Author: xxz1530
 */

#include "Transition.h"

Transition::Transition(State * cState, State *nState, StateEvent sEvent)
{
	currentState = cState;
	nextState = nState;
	triggerEvent = sEvent;
}

bool Transition::guard()
{
	if(currentState->getStatusId() == "DoorStop")
	{
		if((prevState->getStatusId() == "MotorUp") || (prevState->getStatusId() == "MotorDown"))
			return true;
		else
			return false;
	}
	return true;
}

void Transition::addGuard(State * pState)
{
	prevState = pState;
}
