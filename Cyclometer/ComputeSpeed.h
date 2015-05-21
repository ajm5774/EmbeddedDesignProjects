/*
 * ComputeSpeed.h
 *
 *  Created on: May 7, 2015
 *      Author: ajm5774
 */

#ifndef COMPUTESPEED_H_
#define COMPUTESPEED_H_

#include "State.h"
#include "Modes.h"
#include "ComputeDistance.h"
#include "Cyclometer.h"

class ComputeSpeed: public State
{
	public:
		ComputeSpeed();
		void entryAction();
		void exitAction();
		State* accept(StateEvent ev);
};

#endif /* COMPUTESPEED_H_ */
