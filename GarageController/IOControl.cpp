/*
 * IOControl.cpp
 *
 *  Created on: Mar 11, 2015
 *      Author: ajm5774
 */
#include "IOControl.h"
#include "GarageController.h"
#include <sys/neutrino.h>
#include <unistd.h>
#include <iostream>
using namespace std;

bool reset 			= false;
StateEvent event 	= invalid;

const struct sigevent * intHandler (void *arg, int id)
{
	switch (id) {
		case 0:
			reset = true;
			break;
		case 1:
			event = beam_interrupt;
			break;
		case 2:
			event = motor_overcurrent;
			break;
		case 3:
			event = remote_pressed;
			break;
		default:
			break;
	}
	return (NULL);
}

IOControl::IOControl() :
	Control() {
	printf("IOControl made\n");
}

IOControl::IOControl(StateContext * aContext) :
	Control(aContext) {
	context = aContext;
	event = invalid;
	reset = false;
	IOInterruptInit();
	CreateInterrupt(&timer, 200000, 0);//5 times a second
}

void IOControl::IOInterruptInit()
{
	struct sigevent event;
	int interruptID = InterruptAttach (IRQ0,
	                                   intHandler,
	                                   &event,
	                                   sizeof (event),
	                                   0);
	if (interruptID == -1) {
		printf ("can't attach to IRQ\n");
		perror (NULL);
		exit (EXIT_FAILURE);
	}
}

void IOControl::run() {
	struct _pulse pulse;
	startInterrupt(&timer);

	while (true) {
		MsgReceive(timer.chid, &pulse, sizeof(pulse), NULL);

		if(reset)
		{
			resetController();
			reset = false;
		}
		else if(event)
		{
			switch (event) {
				case motor_overcurrent:
					context->queueEvent(motor_overcurrent);
					break;
				case beam_interrupt:
					context->queueEvent(beam_interrupt);
					break;
				case remote_pressed:
					context->queueEvent(remote_pressed);
					break;
				default:
					break;
			}
			event = invalid;
		}
	}

}
