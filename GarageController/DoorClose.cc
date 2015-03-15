/*
 * DoorClose.cc
 *
 *  Created on: Mar 6, 2015
 *      Author: xxz1530
 */

#include "DoorClose.h"
#include <iostream>

/*
 * Constructor for DoorClose state
 */
DoorClose::DoorClose() : State()
{
	//statusId = "DoorClose";
}

/*
 * entry actions for DoorClose state
 */
void DoorClose::entryAction()
{
	std::cout << "DoorClose entry actions: None" << std::endl;
}

/*
 * exit actions for DoorClose state
 */
void DoorClose::exitAction()
{
	std::cout << "DoorClose exit actions: None" << std::endl;
}

string DoorClose::getStatusId()
{
	return "DoorClose";
}
