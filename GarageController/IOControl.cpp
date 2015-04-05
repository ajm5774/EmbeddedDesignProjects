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



IOControl::IOControl() :
	Control() {
	printf("IOControl made\n");
}

IOControl::IOControl(StateContext * aContext) :
	Control(aContext) {
	context = aContext;
	event = invalid;
	input = 0;
	lastInput = 0;
	CreateInterrupt(&timer, 100000, 0);//5 times a second
}

/*void IOControl::IOInterruptInit()
{
	struct sigevent event;
	int interruptID = InterruptAttach (IRQ4,
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
*/

void IOControl::run() {
	struct _pulse pulse;
	startInterrupt(&timer);

	while (true) {
		MsgReceive(timer.chid, &pulse, sizeof(pulse), NULL);

		lastInput = input;
		input = in8(inputHandle);

		if(lastInput != input)
		{
			if((input & FULL_OPEN_PIN_MASK) &&
					!(lastInput & FULL_OPEN_PIN_MASK))
				event = door_open;
			else if((input & FULL_CLOSED_PIN_MASK) &&
					!(lastInput & FULL_CLOSED_PIN_MASK))
				event = door_close;
			else if((input & IR_BROKEN_PIN_MASK) &&
					!(lastInput & IR_BROKEN_PIN_MASK))
				event = beam_interrupt;
			else if ((input & OVERCURRENT_PIN_MASK) &&
					!(lastInput & OVERCURRENT_PIN_MASK))
				event = motor_overcurrent;
			else if ((input & REMOTE_PIN_MASK) &&
					!(lastInput & REMOTE_PIN_MASK))
				event = remote_pressed;
			else
				event = invalid;
		}

		if(event != invalid)
		{
			context->queueEvent(event);
			event = invalid;
		}

	}

}
