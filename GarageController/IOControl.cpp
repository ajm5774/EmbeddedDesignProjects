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
		ch = getchar();

		switch(ch)
		{
			case 'm':
				//context.queueEvent(new QueueItem(MotorOvercurrent));
				cout << "m";
				break;
			case 'i':
				//context.queueEvent(new QueueItem(BeamInterrupt));
				cout << "i";
				break;
			case 'r':
				//context.queueEvent(new QueueItem(RemotePressed));
				cout << "r";
				break;
		}
	}

}
