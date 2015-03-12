/*
 * IOControl.cpp
 *
 *  Created on: Mar 11, 2015
 *      Author: ajm5774
 */
#include "IOControl.h"
#include <iostream>
using namespace std;

IOControl::IOControl(StateContext aContext): Control(aContext)
{
	context = aContext;
}

void IOControl::run()
{
	char ch;
	while(true)
	{
		cin >> ch;

		switch(ch)
		{
			case 'm':
				context.queueEvent(new QueueItem(MotorOvercurrent));
				break;
			case 'i':
				context.queueEvent(new QueueItem(BeamInterrupt));
				break;
			case 'r':
				context.queueEvent(new QueueItem(RemotePressed));
				break;
		}
	}

}
