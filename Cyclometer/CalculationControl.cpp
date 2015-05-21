#include "CalculationControl.h"


int CalculationControl::numRots = 0; //needs lock
bool CalculationControl::bPerformCalcs = false; //needs lock
float CalculationControl::kmhToMph = .621371;
float CalculationControl::elapsedMillis = 0.0;
float CalculationControl::currentSpeed = 0.0;
float CalculationControl::averageSpeed = 0.0;
float CalculationControl::distanceKM = 3;
Mode CalculationControl::unitMode = MPH;
CalculationControl::CalculationControl()
{

}

CalculationControl::CalculationControl(StateContext * context)
{
	reInit();
	CreateInterrupt(&timer, 500000, 0);//5 times a second
	pthread_mutex_init(&calcLock, NULL);
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

	currentSpeed = distance/millisSinceLastCalc*1000;
}

void CalculationControl::calcAverageSpeed(){
	float distance = distanceKM;
	if(unitMode == MPH)
		distance *= .621371;//convert from km to miles

	averageSpeed = distance/elapsedMillis*1000;
}

void CalculationControl::calcDistance(){
	distanceKM += distanceLastCalcKM;
}

void CalculationControl::calcDistanceLastCalc(){
	distanceLastCalcKM = (wheelCircumCM * numRots)/100000;
	numRots = 0;
}

void CalculationControl::performCalcs(){
	//get times
	currentTime = clock();
	millisSinceLastCalc = getMilliDiff(currentTime, timeLastCalc);
	elapsedMillis = getMilliDiff(currentTime, startTime);

	calcDistanceLastCalc();//this calc must come first
	calcDistance();
	calcCurrentSpeed();
	calcAverageSpeed();
	calcDistance();
	timeLastCalc = clock();
}

float CalculationControl::getMilliDiff(clock_t bigClock, clock_t smallClock)
{
	return (float)(1000.0 * (bigClock-smallClock) / CLOCKS_PER_SEC);
}

void CalculationControl::reInit(){
	currentTime = 		clock();
	startTime = 		clock();
	timeLastCalc = 		clock();
	elapsedMillis = 	0.0;
	millisSinceLastCalc = 0.0;

	currentSpeed = 		0.0;
	averageSpeed = 		0.0;
	distanceKM = 		0.0;
	distanceLastCalcKM= 0.0;
	wheelCircumCM = 	190;
	numRots = 			0;
}
