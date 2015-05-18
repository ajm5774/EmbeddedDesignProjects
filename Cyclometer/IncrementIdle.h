/*
 * IncrementIdle.h
 *
 *  Created on: May 7, 2015
 *      Author: ajm5774
 */

#ifndef INCREMENTIDLE_H_
#define INCREMENTIDLE_H_

#include "State.h"

class IncrementIdle: public State
{
	public:
		IncrementIdle();
		void entryAction();
		void exitAction();
		State* accept(StateEvent ev);
};

#endif /* INCREMENTIDLE_H_ */
