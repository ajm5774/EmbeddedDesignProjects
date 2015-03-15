/*
 * IOControl.cpp
 *
 *  Created on: Mar 11, 2015
 *      Author: ajm5774
 */
#include "IOControl.h"
#include <iostream>
using namespace std;

IOControl::IOControl(): Control()
{
	printf("IOControl made\n");
}

IOControl::IOControl(StateContext * aContext): Control(aContext)
{
	context = aContext;
}

void IOControl::run()
{
	char ch;
	cout << "Awaiting character input:\n";
	while(true)
	{
		//system ("/bin/stty raw");
		ch = getchar();

		switch(ch)
		{
			case 'm':
				cout << "m\n";
				context->queueEvent(motor_overcurrent);
				break;
			case 'i':
				cout << "i\n";
				context->queueEvent(beam_interrupt);
				break;
			case 'r':
				cout << "r\n";
				context->queueEvent(remote_pressed);
				break;
			case '\n':
				break;
			default:
				cout << "Key not identified\n";
		}
	}

}
