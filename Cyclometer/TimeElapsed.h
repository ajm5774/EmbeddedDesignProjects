/*
 * TimeElapsed.h
 *
 *  Created on: May 7, 2015
 *      Author: ajm5774
 */

#ifndef TIMEELAPSED_H_
#define TIMEELAPSED_H_

#include "State.h"

class TimeElapsed: public State
{
	public:
		TimeElapsed();
		void entryAction();
		void exitAction();
		State* accept(StateEvent ev);
};

#endif /* TIMEELAPSED_H_ */
