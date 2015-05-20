/*
 * Control.h
 *
 *  Created on: Mar 6, 2015
 *      Author: ajm5774
 */

#ifndef CONTROL_H_
#define CONTROL_H_

#include <pthread.h>
#include "StateContext.h"
#include <sys/neutrino.h>
#include <stdint.h>
#include <hw/inout.h>


#define DAQ_BASE 0x280
#define PORT_LENGTH 		1

//PB Outputs - A
#define DAQ_OUTPUTA 		DAQ_BASE+8
#define ANODE1 				0
#define ANODE2 				1
#define ANODE3 				2
#define ANODE4 				3
#define LED1 				4
#define LED2 				5
#define LED3 				6
#define ANODE1_PIN_MASK 	0x07//0111
#define ANODE2_PIN_MASK 	0x0B//1011
#define ANODE3_PIN_MASK 	0x0D//1101
#define ANODE4_PIN_MASK 	0x0E//1110
#define LED1_PIN_MASK 		0x10
#define LED2_PIN_MASK 		0x20
#define LED3_PIN_MASK 		0x40

//PB Outputs - B
#define DAQ_OUTPUTB			DAQ_BASE+9
#define SEGMENTA 			0
#define SEGMENTB 			1
#define SEGMENTC 			2
#define SEGMENTD 			3
#define SEGMENTE 			4
#define SEGMENTF 			5
#define SEGMENTG 			6
#define SEGMENTDP 			7
#define SEGMENTA_PIN_MASK 	0x01
#define SEGMENTB_PIN_MASK 	0x02
#define SEGMENTC_PIN_MASK 	0x04
#define SEGMENTD_PIN_MASK 	0x08
#define SEGMENTE_PIN_MASK 	0x10
#define SEGMENTF_PIN_MASK 	0x20
#define SEGMENTG_PIN_MASK 	0x40
#define SEGMENTDP_PIN_MASK 	0x80

//PB Inputs - C
#define DAQ_INPUT 			DAQ_BASE+10
#define BOTTON1 			0
#define BOTTON2 			1
#define BOTTON3 			2
#define BOTTON1_PIN_MASK 	0x01
#define BOTTON2_PIN_MASK 	0x02
#define BOTTON3_PIN_MASK 	0x04

//interrupt clear
#define DAQ_CLEAR  			DAQ_BASE + 0
#define CLEAR          		0x02
#define DIO_IRQ        		0x05

//interrupt control
#define DAQ_INTER_CTRL  	DAQ_BASE + 4
#define INIT_BIT       		0x02

//IO CTRL
#define DAQ_CTRL 			DAQ_BASE+11
#define CTRL_INIT 			0x09

class Control
{
public:
	static uint8_t OUTPUTA;
	static uint8_t OUTPUTB;
	StateContext * context;
	Control();
	Control(StateContext * context);
	static uintptr_t inputHandle;
	static uintptr_t outputAHandle;
	static uintptr_t outputBHandle;
	static uintptr_t ctrlHandle;
	static uintptr_t interCtrlHandle;
	static uintptr_t clearHandle;
	virtual void run();
};

#endif /* CONTROL_H_ */
