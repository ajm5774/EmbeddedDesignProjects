/*
 * IncrementManual.h
 *
 *  Created on: May 7, 2015
 *      Author: ajm5774
 */

#ifndef INCREMENTMANUAL_H_
#define INCREMENTMANUAL_H_

#include "State.h"

class IncrementManual: public State
{
	public:
		IncrementManual();
		void entryAction();
		void exitAction();
		State* accept(StateEvent ev);
};

#endif /* INCREMENTMANUAL_H_ */
