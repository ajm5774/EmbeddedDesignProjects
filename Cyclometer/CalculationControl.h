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
#include "Modes.h"
#include "Timer.h"
#include <time.h>
#include <ctime>
#include <stdio.h>
using namespace std;

class CalculationControl: public Control {
public:

	//====inherited
	//variables
	StateContext * context[];

	//functions
	CalculationControl();
	CalculationControl(StateContext * context);
	virtual void run();

	//====other
	//clock_t currentTime;
	//clock_t timeLastCalc;
	//float millisSinceLastCalc;
	//clock_t startTime;

	float distanceLastCalcKM;


	pthread_mutex_t numRotsLock;
	int wheelCircumCM;
	Mode unitMode;
	int numRots; //needs lock
	bool bPerformCalcs; //needs lock
	float kmhToMph;
	int secToHour;
	float elapsedMillis;
	float currentSpeed;
	float averageSpeed;
	float distanceKM;

	void addNumRots(int val);
	void reInit();

private:
	Interrupt timer;
	int timerMicros;

	//functions
	void calcCurrentSpeed();
	void calcAverageSpeed();
	void calcDistance();
	void calcDistanceLastCalc();
	void performCalcs();
	float getMilliDiff(clock_t bigClock, clock_t smallClock);

};

#endif /* CALCULATIONCONTROL_H_ */
