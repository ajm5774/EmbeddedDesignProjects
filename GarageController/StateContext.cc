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
	DoorOpen * dooropen = new DoorOpen();
	DoorClose * doorclose= new DoorClose();
	DoorStop * doorstop= new DoorStop();
	MotorUp * motorup= new MotorUp();
	MotorDown * motordown= new MotorDown();

	currentState = doorclose;

	//StateEvent event1 = remote_pressed;
	// transitions associate with DoorClose state
	Transition DC_trans1(doorclose, motorup, remote_pressed);

	// transitions associate with MotorUp state
	Transition MU_trans1(motorup, dooropen, door_open);
	Transition MU_trans2(motorup, doorstop, remote_pressed);
	Transition MU_trans3(motorup, doorstop, motor_overcurrent);

	// transitions associate with DoorOpen state
	Transition DO_trans1(dooropen, motordown, remote_pressed);

	// transitions associate with MotorDown state
	Transition MD_trans1(motordown, doorclose, door_close);
	Transition MD_trans2(motordown, doorstop, remote_pressed);
	Transition MD_trans3(motordown, motorup, motor_overcurrent);
	Transition MD_trans4(motordown, motorup, beam_interrupt);

	// transitions associate with DoorStop state
	Transition DS_trans1(doorstop, motorup, remote_pressed);
	Transition DS_trans2(doorstop, motordown, remote_pressed);
	// need add guard to check previous state
	DS_trans1.addGuard(motordown);
	DS_trans2.addGuard(motorup);

	// add the states and transition to map
	//stateTransitions.insert(std::make_pair(doorclose, DC_trans1));
	//stateTransitions.insert(std::make_pair(dooropen, DO_trans1));
	stateTransitions[doorclose].push_back(DC_trans1);
	stateTransitions[dooropen].push_back(DO_trans1);

	//Transition MUtrans[] = {MU_trans1, MU_trans2, MU_trans3};
	//stateTransitions.insert(std::make_pair(motorup, MUtrans));
	stateTransitions[motorup].push_back(MU_trans1);
	stateTransitions[motorup].push_back(MU_trans2);
	stateTransitions[motorup].push_back(MU_trans3);

	//Transition MDtrans[] = {MD_trans1, MD_trans2, MD_trans3, MD_trans4};
	//stateTransitions.insert(std::make_pair(motordown, MDtrans));
	stateTransitions[motordown].push_back(MD_trans1);
	stateTransitions[motordown].push_back(MD_trans2);
	stateTransitions[motordown].push_back(MD_trans3);
	stateTransitions[motordown].push_back(MD_trans4);

	//Transition DStrans[] = {DS_trans1, DS_trans2};
	//stateTransitions.insert(std::make_pair(doorstop, DStrans));
	stateTransitions[doorstop].push_back(DS_trans1);
	stateTransitions[doorstop].push_back(DS_trans2);

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

	//Transition trans[4]= stateTransitions[*currentState];
	std::vector<Transition> trans;
	trans = stateTransitions[currentState];
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


