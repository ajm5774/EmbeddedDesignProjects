/*
 * CalculationControl.h
 *
 *  Created on: May 18, 2015
 *      Author: ajm5774
 */

#ifndef CALCULATIONCONTROL_H_
#define CALCULATIONCONTROL_H_

#include "StateContext.h"
#include "Control.h"


class CalculationControl: public Control
{
public:

//====inherited
	//variables
	StateContext * context;

	//functions
	CalculationControl();
	CalculationControl(StateContext * context);
	virtual void run();

//====other
	time_t currentTime;
	time_t timeLastCalc;
	time_t startTime;
	time_t elapsedTime;
	float currentSpeed;
	float averageSpeed;
	float distance;
	int wheelCircumCM;
	Mode unitMode;
	mutex calcLock;
	int numRots; 		//needs lock
	bool performCalcs;	//needs lock

private:
	Interrupt timer;

	//functions
	void calcCurrentSpeed();
	void calcAverageSpeed();
	void calcDistance();
	void calcElapsedTime();
	void performCalcs();
	void reInit();

};

#endif /* CALCULATIONCONTROL_H_ */
