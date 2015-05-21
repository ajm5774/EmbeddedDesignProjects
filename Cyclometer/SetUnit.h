/*
 * SetUnit.h
 *
 *  Created on: May 7, 2015
 *      Author: ajm5774
 */

#ifndef SETUNIT_H_
#define SETUNIT_H_

#include "State.h"
#include "StateEvents.h"
#include "StateContext.h"
#include "Modes.h"
#include "Cyclometer.h"
#include "SetCircumference.h"
#include "LEDControl.h"

class SetUnit: public State
{
	public:
		SetUnit();
		void entryAction();
		void exitAction();
		State* accept(StateEvent ev);

		Mode unitMode;
};

#endif /* SETUNIT_H_ */
