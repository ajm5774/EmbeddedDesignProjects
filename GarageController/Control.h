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
#define PORT_LENGTH 		1

//PB Inputs
#define DAQ_INPUT 			DAQ_BASE+8
#define FULL_OPEN_PIN 		0
#define FULL_CLOSED_PIN 	1
#define IR_BROKEN_PIN 		2
#define OVERCURRENT_PIN 	3
#define REMOTE_PIN 			4

//PB Outputs
#define DAQ_OUTPUT DAQ_BASE+9
#define MOTOR_UP_PIN 		0
#define MOTOR_DOWN_PIN 		1
#define IR_BEAM_ON 			2
#define RESET_SIM 			3

//IO CTRL
#define DAQ_CTRL 			DAQ_BASE+11
#define CTRL_INIT 			0x10

//Interrupts
#define INTERRUPT_CTRL		DAQ_BASE+4
#define IRQ_ENABLE			2

class Control
{
public:
	StateContext * context;
	Control();
	Control(StateContext * context);
	static uintptr_t inputHandle, outputHandle, ctrlHandle, interHandle;
	virtual void run();
};

#endif /* CONTROL_H_ */
