/*
 * BeamControl.h
 *
 *  Created on: Mar 6, 2015
 *      Author: ajm5774
 */

#ifndef BEAMCONTROL_H_
#define BEAMCONTROL_H_

class BeamControl: public Control
{
	static bool beamOn;

public:
	StateContext context;
	BeamControl();
	BeamControl(StateContext context);
	void run();
	void setContext(StateContext context);
};

#endif /* BEAMCONTROL_H_ */
