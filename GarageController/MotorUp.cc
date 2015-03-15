/*
 * MotorUp.cc
 *
 *  Created on: Mar 6, 2015
 *      Author: xxz1530
 */

#include "MotorUp.h"
#include "MotorControl.h"

MotorUp::MotorUp() : State()
{
	statusId = "MotorUp";
}

void MotorUp::entryAction()
{
	MotorControl::motorUp = true;
}

void MotorUp::exitAction()
{
	MotorControl::motorUp = false;
}


