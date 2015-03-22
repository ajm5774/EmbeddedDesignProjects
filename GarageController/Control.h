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
#include <sys/neutrino.h>


#define DAQ_BASE 0x280
#define DATA_OUTPUT DAQ_BASE+8
#define DATA_INPUT DAQ_BASE+9
#define DATA_CTRL DAQ_BASE+11
#define PORT_LENGTH 1


class Control
{
public:
	StateContext * context;
	Control();
	Control(StateContext * context);
	static uintptr_t inputHandle, outputHandle, ctrlHandle;
	virtual void run();
};

#endif /* CONTROL_H_ */
