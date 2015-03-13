/*
 * MotorDown.cc
 *
 *  Created on: Mar 10, 2015
 *      Author: xxz1530
 */

#include "MotorDown.h"
#include "MotorControl.h"
#include "BeamControl.h"


MotorDown::MotorDown()
{
	statusId = "MotorDown";
}

void MotorDown::entryAction()
{
	motorDown = true;
	beamOn = true;
}

void MotorDown::exitAction()
{
	beamOn = false;
	motorDown = false;
}


