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

uintptr_t Control::ctrlHandle = mmap_device_io(PORT_LENGTH, DAQ_CTRL);
uintptr_t Control::inputHandle = mmap_device_io(PORT_LENGTH,DAQ_INPUT);
uintptr_t Control::outputAHandle = mmap_device_io(PORT_LENGTH,DAQ_OUTPUTA);
uintptr_t Control::outputBHandle = mmap_device_io(PORT_LENGTH,DAQ_OUTPUTB);
uintptr_t Control::interCtrlHandle = mmap_device_io( PORT_LENGTH, DAQ_INTER_CTRL );
uintptr_t Control::clearHandle = mmap_device_io(PORT_LENGTH, DAQ_CLEAR);

uint8_t Control::OUTPUTA = 0x00;
uint8_t Control::OUTPUTB = 0x00;

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


