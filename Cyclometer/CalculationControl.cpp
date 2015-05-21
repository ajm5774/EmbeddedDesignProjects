#include "CalculationControl.h"

CalculationControl::CalculationControl()
{

}

CalculationControl::CalculationControl(StateContext * context)
{
	kmhToMph = .621371;
	secToHour = 3600;
	reInit();
	timerMicros = 1000000;
	bPerformCalcs = false; //needs lock
	CreateInterrupt(&timer, 0, 1);//5 times a second
	pthread_mutex_init(&numRotsLock, NULL);
}

void CalculationControl::run()
{
	struct _pulse pulse;
	startInterrupt(&timer);

	while(true)
	{
		MsgReceive(timer.chid, &pulse, sizeof(pulse), NULL);

		if(bPerformCalcs)
			performCalcs();
	}
}

void CalculationControl::calcCurrentSpeed(){
	float distance = distanceLastCalcKM;
	if(unitMode == MPH)
		distance *= .621371;//convert from km to miles

	currentSpeed = (float)distance*1000.0 * (float)secToHour/(timerMicros/1000.0);
}

void CalculationControl::calcAverageSpeed(){
	float distance = distanceKM;
	if(unitMode == MPH)
		distance *= .621371;//convert from km to miles

	averageSpeed = (float)(distance*1000.0 * (float)secToHour/elapsedMillis);
}

void CalculationControl::calcDistance(){
	distanceKM += distanceLastCalcKM;
}

void CalculationControl::calcDistanceLastCalc(){
	distanceLastCalcKM = ((float)(wheelCircumCM * numRots))/100000.0;
	addNumRots(-numRots);
}

void CalculationControl::performCalcs(){
	//get times
	elapsedMillis += timerMicros /1000;
	printf("%f\n", elapsedMillis);

	calcDistanceLastCalc();//this calc must come first
	calcDistance();
	calcCurrentSpeed();
	calcAverageSpeed();
}

void CalculationControl::addNumRots(int val)
{
	pthread_mutex_lock(&numRotsLock);
	numRots+= val;
	pthread_mutex_unlock(&numRotsLock);
}

void CalculationControl::reInit(){
	elapsedMillis =		0.0;

	currentSpeed = 		0.0;
	averageSpeed = 		0.0;
	distanceKM = 		0.0;
	distanceLastCalcKM= 0.0;
	wheelCircumCM = 	190;
	numRots = 			0;
	//bPerformCalcs = false; //needs lock
	unitMode = MPH;
}
