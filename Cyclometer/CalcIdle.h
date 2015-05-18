/*
 * CalcIdle.h
 *
 *  Created on: May 7, 2015
 *      Author: ajm5774
 */

#ifndef CALCIDLE_H_
#define CALCIDLE_H_

#include "State.h"

class CalcIdle: public State
{
	public:
		CalcIdle();
		void entryAction();
		void exitAction();
		State* accept(StateEvent ev);
};

#endif /* CALCIDLE_H_ */
