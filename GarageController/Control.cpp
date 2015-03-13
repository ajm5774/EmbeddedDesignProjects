/*
 * Control.cpp
 *
 *  Created on: Mar 12, 2015
 *      Author: ajm5774
 */
#include "Control.h"
#include <stdio.h>

Control::Control(){

	printf("Control made");
}

Control::Control(StateContext aContext)
{
	context = aContext;
}

void Control::run()
{
	printf("Control made");
}


