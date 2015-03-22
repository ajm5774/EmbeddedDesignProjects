/*
 * IOControl.cpp
 *
 *  Created on: Mar 11, 2015
 *      Author: ajm5774
 */
#include "OverCurrentControl.h"
#include <iostream>
using namespace std;

OverCurrentControl::OverCurrentControl(): Control()
{
	printf("OverCurrentControl made");
}

OverCurrentControl::OverCurrentControl(StateContext * aContext): Control(aContext)
{
	context = aContext;
	CreateInterrupt(&timer, 0, 5);//every 5 seconds
}

void OverCurrentControl::run()
{
	struct _pulse pulse;
	startInterrupt(&timer);

	while(true)
	{
		MsgReceive(timer.chid, &pulse, sizeof(pulse), NULL);
		//printf("Checking for overcurrent\n");
	}
}
