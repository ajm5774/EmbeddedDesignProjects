/*
 * MotorDown.cc
 *
 *  Created on: Mar 10, 2015
 *      Author: xxz1530
 */

#include "MotorDown.h"
#include "MotorControl.h"
#include "BeamControl.h"


MotorDown::MotorDown() : State()
{
	statusId = "MotorDown";
}

void MotorDown::entryAction()
{
	MotorControl::motorUp = false;
	MotorControl::motorDown = true;
	BeamControl::beamOn = true;
}

void MotorDown::exitAction()
{
	BeamControl::beamOn = false;
	MotorControl::motorDown = false;
	MotorControl::motorUp = false;
}


