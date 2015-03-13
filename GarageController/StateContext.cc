/*
 * StateContext.cc
 *
 *  Created on: Mar 12, 2015
 *      Author: xxz1530
 */

#include "StateContext.h"
#include "DoorClose.h"
#include "DoorOpen.h"
#include "DoorStop.h"
#include "MotorUp.h"
#include "MotorDown.h"

StateContext::StateContext()
{
	// creating the states
	/*DoorOpen dooropen;
	DoorClose doorclose;
	DoorStop doorstop;
	MotorUp motorup;
	MotorDown motordown;

	//StateEvent event1 = remote_pressed;
	// transitions associate with DoorClose state
	Transition DC_trans1(&doorclose, &motorup, remote_pressed);

	// transitions associate with MotorUp state
	Transition MU_trans1(&motorup, &dooropen, door_open);
	Transition MU_trans2(&motorup, &doorstop, remote_pressed);
	Transition MU_trans3(&motorup, &doorstop, motor_overcurrent);

	// transitions associate with DoorOpen state
	Transition DO_trans1(&dooropen, &motordown, remote_pressed);

	// transitions associate with MotorDown state
	Transition MD_trans1(&motordown, &doorclose, door_close);
	Transition MD_trans2(&motordown, &doorstop, remote_pressed);
	Transition MotorDown_trans3(&motordown, &motorup, motor_overcurrent);
	Transition MotorDown_trans4(&motordown, &motorup, beam_interrupt);

	// transitions associate with DoorStop state
	Transition DS_trans1(&doorstop, &motorup, remote_pressed);
	Transition DS_trans2(&doorstop, &motordown, remote_pressed);
	// need addguard to check previous state

	// add the states and transition to map
	//stateTransitions.insert();*/
}

void StateContext::queueEvent(StateEvent event)
{
}

void StateContext::accept(StateEvent event)
{

}
