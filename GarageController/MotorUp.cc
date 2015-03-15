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
	//std::cout << "MotorUp entry Actions: motorUp = true" << std::endl;
}

/*
 * exit actions for MotorUp state
 */
void MotorUp::exitAction()
{
	MotorControl::motorUp = false;
	//std::cout << "MotorUp exit Actions: motorUp = false" << std::endl;
}

string MotorUp::getStatusId()
{
	return "MotorUp";
}


