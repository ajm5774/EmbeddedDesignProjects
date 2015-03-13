/*
 * MotorUp.cc
 *
 *  Created on: Mar 6, 2015
 *      Author: xxz1530
 */

#include "MotorUp.h"
#include "MotorControl.h"

MotorUp::MotorUp()
{
	statusId = "MotorUp";
}

void MotorUp::entryAction()
{
	motorUp = true;
}

void MotorUp::exitAction()
{
	motorUp = false;
}


