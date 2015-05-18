/*
 * CalcManual.h
 *
 *  Created on: May 7, 2015
 *      Author: ajm5774
 */

#ifndef CALCMANUAL_H_
#define CALCMANUAL_H_

#include "State.h"

class CalcManual: public State
{
	public:
		CalcManual();
		void entryAction();
		void exitAction();
		State* accept(StateEvent ev);
};

#endif /* CALCMANUAL_H_ */
