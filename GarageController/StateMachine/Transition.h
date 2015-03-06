/*
 * Transition.h
 *
 *  Created on: Mar 6, 2015
 *      Author: ajm5774
 */

#ifndef TRANSITION_H_
#define TRANSITION_H_

class Transition
{
	State * nextState;
	State * currentState;

public:
	Transition(State * nextState);
	bool guard();
	void setState(State * currState);
	void addGuard(bool (*f)());
};

#endif /* TRANSITION_H_ */
