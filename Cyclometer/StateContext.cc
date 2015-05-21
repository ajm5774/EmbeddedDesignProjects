/*
 * StateContext.cc
 *
 *  Created on: Mar 12, 2015
 *      Author: xxz1530
 */

#include "StateContext.h"
#include <iostream>
#include "SetUnit.h"
#include "Cyclometer.h"

/*
 * StateContext constructor
 */
StateContext::StateContext()
{
	hasEvent = false;
	State * startState = new SetUnit();
	currentStates[0] = startState;
}

/*
 * Adds the event to concurrent queue
 */
void StateContext::queueEvent(StateEvent event)
{
	QueueItem item(event);
	queue.enqueue(&item);

	pthread_sleepon_lock();
	hasEvent = true;
	pthread_sleepon_signal(&hasEvent);
	pthread_sleepon_unlock();
}

void StateContext::accept(StateEvent event)
{
	if(event == reset)
	{
		resetSystem();
		return;
	}

	int i;
	State * transitionedState;
	int currStateLen = (sizeof(currentStates)/sizeof(State*));
	for(i=0; i < currStateLen;i++)
	{
		transitionedState = currentStates[i]->accept(event);
		if(transitionedState != currentStates[i])
		{
			currentStates[i]->exitAction();
			currentStates[i] = transitionedState;
			currentStates[i]->entryAction();
		}
	}
}

void StateContext::run()
{
	int i;
	QueueItem * nextItem;
	State * transitionedState;

	currentStates[0]->entryAction();
	while(true)
	{
		pthread_sleepon_lock();
		while(!hasEvent)
		{
			pthread_sleepon_wait(&hasEvent);
		}
		nextItem = queue.dequeue();

		if(nextItem)
		{
			accept(nextItem->event);
		}
		else
			hasEvent = false;
		pthread_sleepon_unlock();
	}
}

void StateContext::reInit()
{
	State start = SetUnit();
	currentStates[0] = &start;
	queue = ConcurrentQueue();
	currentStates[0]->entryAction();
}


