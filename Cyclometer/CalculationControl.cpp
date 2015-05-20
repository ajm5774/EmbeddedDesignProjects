/*
 * CalculationControl.cpp
 *
 *  Created on: May 19, 2015
 *      Author: msa3600
 */




#include "CalculationControl.h"
#include <unistd.h>
#include <stdint.h>
#include <sys/mman.h>
#include <sys/neutrino.h>
#include <hw/inout.h>
#include <math.h>



uintptr_t ctrlCAHandle;
uint8_t cycles;
uint8_t distanceCycles;



CalculationControl::CalculationControl() {
	// TODO Auto-generated constructor stub

}

CalculationControl::~CalculationControl() {
	// TODO Auto-generated destructor stub
}



void CalculationControl::entry(){
}

void CalculationControl::exit(){
}


void* CalculationControl::runCProcess(void){


	while (true){
		cycles = in8(ctrlCAHandle);
			if(gotCycle==0 && (cycles )){
					gotCycle++;
					cycleCount++;
					cycling = true;
					if(calculate){
						distanceTraveled =  distanceTraveled + (speed * ((((float)elapsedMinuets*2) + (float)elapsedSeconds)/3600.0));

						avSpeed = (avSpeed * ((float) cycleCount / ((float)cycleCount + 1))) + (speed * ( 1 / ((float)cycleCount+1)));

					}
			}else if( gotCycle == 1 && !(cycles )){
						gotCycle--;
					}
			else{
				nanosleep(&ctsim, NULL);
				}
				}

	return NULL;
}


void* CalculationControl::runProcessSpeed(void){
	while(true){
				int curr = cycleCount - prevCycleCount;
				if (curr!=0){
					stoped = 0;
					speed = (float)circumference / 100000;
					speed = speed * (float)curr * 3600;
					if(khm){
					}else{
						speed = speed * .621371192;
						avSpeed = avSpeed * .621371192;
					}
				prevCycleCount=cycleCount;
				sleep(1);

		}
	return NULL;
}

void* CalculationControl::runProcessTime(void){
	while(true){
		if(calculate == true){
			if(cycling == true){
				sleep(1);
				if (elapsedSeconds==59){
					elapsedSeconds = 0;
					elapsedMinuets++;
				}else{
					elapsedSeconds++;
				}
			}}else{
			sleep(.5);
		}
	}

	return NULL;}

void CalculationControl::reInit(){
	elapsedSeconds =0;
	elapsedMinuets=0;
	cycleCount =0;
	prevCycleCount =0;
	speed =0;
	avSpeed =0;
	distanceTraveled = 0;
	exit();

}
