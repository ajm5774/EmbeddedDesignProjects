#include <cstdlib>
#include <stdio.h>
#include <pthread.h>
#include <iostream>
#include <hw/inout.h>
#include "ConcurrentQueue.h"
#include "QueueItem.h"
#include "StateEvents.h"
#include "Control.h"
#include "IOControl.h"
#include "MotorControl.h"
#include "OvercurrentControl.h"
#include "BeamControl.h"
#include "StateContext.h"
#include <unistd.h>
#include "DoorOpen.h"
#include "DoorClose.h"
#include "DoorStop.h"
#include "MotorUp.h"
#include "MotorDown.h"
#include "Transition.h"
#include "GarageController.h"

using namespace std;

const int numThreads = 4;
pthread_t * threads[numThreads];
StateContext * context;


typedef struct
{
	Control * control;
} pthreadBundle;

static void * controlWrapper(void * bund)
{
	((pthreadBundle *) bund)->control->run();
	return NULL;
}

void startControlThreads()
{
	int i;
	int numControls = 4;
	IOControl * io = new IOControl(context);
	MotorControl * mc = new MotorControl(context);
	OverCurrentControl * occ = new OverCurrentControl(context);
	BeamControl * bc = new BeamControl(context);
	Control * controls[] = {io, mc, occ, bc};


	pthread_attr_t threadAttributes ;
	int policy ;
	struct sched_param parameters ;

	pthread_attr_init(&threadAttributes) ;		// initialize thread attributes structure -- must do before any other activity on this struct
	pthread_getschedparam(pthread_self(), &policy, &parameters) ;	// get this main thread's scheduler parameters
	parameters.sched_priority-- ;									// lower the priority
	pthread_attr_setschedparam(&threadAttributes, &parameters) ;	// set up the pthread_attr struct with the updated priority

	// now create the threads and pass along its thread number from the loop counter.
	pthreadBundle bundle = {NULL};
	for(i =0; i < numControls; i++)
	{
		bundle.control = controls[i];
		pthread_create( threads[i], &threadAttributes, controlWrapper, (void *)&bundle);
	}
}

void IOInit()
{
	//enables interrupts
	out8(Control::interHandle, IRQ_ENABLE);

	//set IO direction
	out8(Control::ctrlHandle, CTRL_INIT);
}

int main(int argc, char *argv[]) {
	context = new StateContext();
	IOInit();
	startControlThreads();

	context->run();
}

void resetController()
{
	int i;
	for(i = 0; i < numThreads;i++)
	{
		pthread_kill(*threads[i], 0);
	}
	main(0,0);
}


