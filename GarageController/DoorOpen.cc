/*
 * DoorOpen.cc
 *
 *  Created on: Mar 10, 2015
 *      Author: xxz1530
 */

#include "DoorOpen.h"
#include <iostream>

/*
 * DoorOpen state constructor
 */
DoorOpen::DoorOpen() : State()
{
}

/*
 * entry actions for DoorOpen state
 */
void DoorOpen::entryAction()
{
	std::cout << "DoorOpen entry actions: None" << std::endl;
}

/*
 * exit actions for DoorOpen state
 */
void DoorOpen::exitAction()
{
	std::cout << "DoorClose exit actions: None" << std::endl;
}

string DoorOpen::getStatusId()
{
	return "DoorOpen";
}
