/*
 * StateContext.cc
 *
 *  Created on: Mar 12, 2015
 *      Author: xxz1530
 */

#include "StateContext.h"
#include <vector>
#include <iostream>

/*
 * StateContext constructor
 */
StateContext::StateContext()
{
	// creating the states
	dooropen = new DoorOpen();
	doorclose= new DoorClose();
	doorstop= new DoorStop();
	motorup= new MotorUp();
	motordown= new MotorDown();

	currentState = doorclose;

	CreateInterrupt(&timer, 500000, 0);//2 times a second
}

/*
 * Adds the event to concurrent queue
 */
void StateContext::queueEvent(StateEvent event)
{
	QueueItem item(event);
	queue.enqueue(&item);
}

void StateContext::accept(StateEvent event)
{
	cout << "Processing event " << event << "\n";

	Transition * aTrans = getTransition(currentState, event);

	// transition taken
	if(aTrans->triggerEvent != invalid)
	{
		previousState = currentState;
		currentState->exitAction();
		currentState = aTrans->nextState;
		currentState->entryAction();
		cout << "Moved to state: " << currentState->getStatusId()<< "\n";
	}
}

void StateContext::run()
{
	QueueItem * nextItem;

	struct _pulse pulse;
	startInterrupt(&timer);
	while(true)
	{
		MsgReceive(timer.chid, &pulse, sizeof(pulse), NULL);
		nextItem = queue.dequeue();

		if(nextItem)
		{
			accept(nextItem->event);
		}
	}
}

Transition * StateContext::getTransition(State * state, StateEvent event)
{
	if(state == dooropen)
	{
		if(event == remote_pressed)
			return new Transition(dooropen, motordown, remote_pressed);
	}
	else if(state == doorclose)
	{
		if(event == remote_pressed)
			return new Transition(doorclose, motorup, remote_pressed);
	}
	else if(state == motorup)
	{
		if(event == door_open)
			return new Transition(motorup, dooropen, door_open);
		else if(event == remote_pressed)
			return new Transition(motorup, doorstop, remote_pressed);
		else if(event == motor_overcurrent)
			return new Transition(motorup, doorstop, motor_overcurrent);
	}
	else if(state == motordown)
	{
		if(event == door_close)
			return new Transition(motordown, doorclose, door_close);
		else if(event == remote_pressed)
			return new Transition(motordown, doorstop, remote_pressed);
		else if(event == motor_overcurrent)
			return new Transition(motordown, motorup, motor_overcurrent);
		else if(event == beam_interrupt)
			return new Transition(motordown, motorup, beam_interrupt);
	}
	else if(state == doorstop)
	{
		if(event == remote_pressed)
		{
			if(previousState == motordown)
				return new Transition(doorstop, motorup, remote_pressed);
			else if(previousState == motorup)
				return new Transition(doorstop, motordown, remote_pressed);
		}
	}

	return new Transition(doorstop, motordown, invalid);
}


