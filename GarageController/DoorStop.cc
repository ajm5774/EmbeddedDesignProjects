/*
 * DoorStop.cc
 *
 *  Created on: Mar 10, 2015
 *      Author: xxz1530
 */

#include "DoorStop.h"
#include <iostream>

/*
 * Constructor for DoorStop state
 */
DoorStop::DoorStop() : State()
{
	//statusId = "DoorStop";
}

/*
 * entry actions for DoorStop state
 */
void DoorStop::entryAction()
{
	std::cout << "DoorStop entry actions: None" << std::endl;
}

/*
 * exit actions for DoorStop state
 */
void DoorStop::exitAction()
{
	std::cout << "DoorStop exit actions: None" << std::endl;
}

string DoorStop::getStatusId()
{
	return "DoorStop";
}
