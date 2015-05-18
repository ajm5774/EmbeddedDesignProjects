/*
 * CalcAuto.h
 *
 *  Created on: May 7, 2015
 *      Author: ajm5774
 */

#ifndef CALCAUTO_H_
#define CALCAUTO_H_

#include "State.h"

class CalcAuto: public State
{
	public:
		CalcAuto();
		void entryAction();
		void exitAction();
		State* accept(StateEvent ev);
};

#endif /* CALCAUTO_H_ */
