/*
 * MotorUp.cc
 *
 *  Created on: Mar 6, 2015
 *      Author: xxz1530
 */

#include "MotorUp.h"
#include "MotorControl.h"
#include <iostream>

/*
 * Constructor for MotorUp state
 */
MotorUp::MotorUp() : State()
{
}

/*
 * entry actions for MotorUp state
 */
void MotorUp::entryAction()
{
	MotorControl::motorUp = true;
	MotorControl::motorDown = false;
}

/*
 * exit actions for MotorUp state
 */
void MotorUp::exitAction()
{
	MotorControl::motorUp = false;
	MotorControl::motorDown = false;
}

string MotorUp::getStatusId()
{
	return "MotorUp";
}


