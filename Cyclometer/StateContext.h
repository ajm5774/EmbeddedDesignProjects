/*
 * StateContext.h
 *
 *  Created on: Mar 6, 2015
 *      Author: ajm5774
 */

#ifndef STATECONTEXT_H_
#define STATECONTEXT_H_

#include "State.h"
#include <pthread.h>
#include "StateEvents.h"
#include <map>
#include "ConcurrentQueue.h"
#include "QueueItem.h"
#include <vector>
#include <sys/neutrino.h>

class StateContext {
	State * currentStates[];
	bool hasEvent;

public:
	StateContext();
	void queueEvent(StateEvent event);
	void accept(StateEvent event);
	void run();

private:
	ConcurrentQueue queue;
};

#endif /* STATECONTEXT_H_ */
