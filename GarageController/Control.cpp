/*
 * Control.cpp
 *
 *  Created on: Mar 12, 2015
 *      Author: ajm5774
 */
#include "Control.h"
#include <stdio.h>
#include <stdint.h>
#include <sys/mman.h>

uintptr_t Control::ctrlHandle = mmap_device_io(PORT_LENGTH, DATA_CTRL);
uintptr_t Control::inputHandle = mmap_device_io(PORT_LENGTH,DATA_INPUT);
uintptr_t Control::outputHandle = mmap_device_io(PORT_LENGTH,DATA_OUTPUT);

Control::Control(){

	printf("Control made\n");
}

Control::Control(StateContext * aContext)
{
	context = aContext;
}

void Control::run()
{
	printf("Control made");
}


