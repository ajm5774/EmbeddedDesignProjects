/*
 * IncrementAuto.h
 *
 *  Created on: May 7, 2015
 *      Author: ajm5774
 */

#ifndef INCREMENTAUTO_H_
#define INCREMENTAUTO_H_

#include "State.h"

class IncrementAuto: public State
{
	public:
		IncrementAuto();
		void entryAction();
		void exitAction();
		State* accept(StateEvent ev);
};

#endif /* INCREMENTAUTO_H_ */
