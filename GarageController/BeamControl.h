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
#include "Timer.h"
#include <sys/neutrino.h>

#define BASE_ADDR 280
#define IO_PORT_SIZE 1
#define BBH_CTRL_ADDR 0x37

class BeamControl: public Control
{
public:
	static bool beamOn;
	StateContext * context;
	BeamControl();
	BeamControl(StateContext * context);
	virtual void run();

private:
	uintptr_t beamBrokenH;
	Interrupt timer;
};

#endif /* BEAMCONTROL_H_ */
