/*
 * StateContext.cc
 *
 *  Created on: Mar 12, 2015
 *      Author: xxz1530
 */

#include "StateContext.h"
#include <vector>

/*
 * StateContext constructor
 */
StateContext::StateContext()
{
	// creating the states
	//DoorOpen dooropen;
	//DoorClose doorclose;
	//DoorStop doorstop;
	//MotorUp motorup;
	//MotorDown motordown;

	//StateEvent event1 = remote_pressed;
	// transitions associate with DoorClose state
	/*Transition DC_trans1(&doorclose, &motorup, remote_pressed);

	// transitions associate with MotorUp state
	Transition MU_trans1(&motorup, &dooropen, door_open);
	Transition MU_trans2(&motorup, &doorstop, remote_pressed);
	Transition MU_trans3(&motorup, &doorstop, motor_overcurrent);

	// transitions associate with DoorOpen state
	Transition DO_trans1(&dooropen, &motordown, remote_pressed);

	// transitions associate with MotorDown state
	Transition MD_trans1(&motordown, &doorclose, door_close);
	Transition MD_trans2(&motordown, &doorstop, remote_pressed);
	Transition MD_trans3(&motordown, &motorup, motor_overcurrent);
	Transition MD_trans4(&motordown, &motorup, beam_interrupt);

	// transitions associate with DoorStop state
	Transition DS_trans1(&doorstop, &motorup, remote_pressed);
	Transition DS_trans2(&doorstop, &motordown, remote_pressed);
	// need addguard to check previous state

	// add the states and transition to map
	stateTransitions.insert(std::make_pair(doorclose, DC_trans1));
	stateTransitions.insert(std::make_pair(dooropen, DO_trans1));

	Transition MUtrans[] = {MU_trans1, MU_trans2, MU_trans3};
	stateTransitions.insert(std::make_pair(motorup, MUtrans));

	Transition MDtrans[] = {MD_trans1, MD_trans2, MD_trans3, MD_trans4};
	stateTransitions.insert(std::make_pair(motordown, MDtrans));

	Transition DStrans[] = {DS_trans1, DS_trans2};
	stateTransitions.insert(std::make_pair(doorstop, DStrans));*/
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

	/*Transition trans[4]= stateTransitions[*currentState];

	// loop counter
	int i = 0;
	int length = sizeof(trans)/sizeof(Transition);
	// loop through all the transition associate with the current state
	for(i = 0; i < length; i++)
	{
		if(trans[i].triggerEvent == event)
		{
			// check guard condition
			if(trans[i].guard())
			{
				// transition taken
				previousState = currentState;
				currentState->exitAction();
				currentState = trans[i].nextState;
				currentState->entryAction();
			}
		}
	}*/



}
