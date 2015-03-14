/*
 * BeamControl.h
 *
 *  Created on: Mar 6, 2015
 *      Author: ajm5774
 */

#ifndef BEAMCONTROL_H_
#define BEAMCONTROL_H_

#include "Control.h"
#include "StateContext.h"

class BeamControl: public Control
{
public:
	static bool beamOn;
	StateContext * context;
	BeamControl(StateContext * context);
	virtual void run();
};

#endif /* BEAMCONTROL_H_ */
