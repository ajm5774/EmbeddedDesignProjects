/*
 * MotorDown.cc
 *
 *  Created on: Mar 10, 2015
 *      Author: xxz1530
 */

#include "MotorDown.h"
#include "MotorControl.h"
#include "BeamControl.h"
#include <iostream>

/*
 * Constructor for MotorDown state
 */
MotorDown::MotorDown() : State()
{
}

/*
 * entry actions for MotorDown state
 */
void MotorDown::entryAction()
{
	MotorControl::motorUp = false;
	MotorControl::motorDown = true;
	BeamControl::beamOn = true;
}

/*
 * exit actions for MotorDown state
 */
void MotorDown::exitAction()
{
	BeamControl::beamOn = false;
	MotorControl::motorDown = false;
	MotorControl::motorUp = false;
}

string MotorDown::getStatusId()
{
	return "MotorDown";
}

