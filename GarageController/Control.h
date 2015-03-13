/*
 * Control.h
 *
 *  Created on: Mar 6, 2015
 *      Author: ajm5774
 */

#ifndef CONTROL_H_
#define CONTROL_H_

#include <pthread.h>
#include "StateContext.h"

class Control
{
	StateContext context;

public:
	Control(StateContext context);
	void start();

private:
	pthread_t thread;
	void * run(void * v);
};

#endif /* CONTROL_H_ */
