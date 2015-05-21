/*
 * SetCircumference.h
 *
 *  Created on: May 7, 2015
 *      Author: ajm5774
 */

#ifndef SETCIRCUMFERENCE_H_
#define SETCIRCUMFERENCE_H_

#include "State.h"
#include "Cyclometer.h"
#include "ComputeSpeed.h"

class SetCircumference: public State
{
	public:
		SetCircumference();
		void entryAction();
		void exitAction();
		State* accept(StateEvent ev);

		int tireCircumCM;
};

#endif /* SETCIRCUMFERENCE_H_ */
