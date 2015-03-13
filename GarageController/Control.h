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
public:
	StateContext context;
	Control();
	Control(StateContext context);
	void run();
};

#endif /* CONTROL_H_ */
