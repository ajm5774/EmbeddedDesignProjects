/*
 * ComputeDistance.h
 *
 *  Created on: May 7, 2015
 *      Author: ajm5774
 */

#ifndef COMPUTEDISTANCE_H_
#define COMPUTEDISTANCE_H_

#include "State.h"

class ComputeDistance: public State
{
	public:
		ComputeDistance();
		void entryAction();
		void exitAction();
		State* accept(StateEvent ev);
};

#endif /* COMPUTEDISTANCE_H_ */
