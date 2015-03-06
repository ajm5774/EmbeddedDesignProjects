/*
 * StateContext.h
 *
 *  Created on: Mar 6, 2015
 *      Author: ajm5774
 */

#ifndef STATECONTEXT_H_
#define STATECONTEXT_H_

class StateContext
{
	State * currentState;
	State * previousState;
	std::map<State, Transition[]> stateTransitions;

public:
	void queueEvent(StateEvents event);

private:
	void accept(StateEvents event);
};

#endif /* STATECONTEXT_H_ */
