/*
 * CalcActive.h
 *
 *  Created on: May 7, 2015
 *      Author: ajm5774
 */

#ifndef CALCACTIVE_H_
#define CALCACTIVE_H_

#include "State.h"

class CalcActive: public State
{
	public:
		CalcActive();
		void entryAction();
		void exitAction();
		State* accept(StateEvent ev);
};

#endif /* CALCACTIVE_H_ */
