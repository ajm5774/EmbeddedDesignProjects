#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <pthread.h>
#include <iostream>
#include <hw/inout.h>
#include "ConcurrentQueue.h"
#include "QueueItem.h"
#include "StateEvents.h"
#include "Control.h"
#include "StateContext.h"
#include "LEDDisplayControl.h"
#include "LEDControl.h"
#include "InterruptControl.h"
#include "CalculationControl.h"
#include <unistd.h>
#include <sys/neutrino.h>
#include <sys/mman.h>

const int numThreads = 4;
pthread_t * threads[numThreads];
StateContext * context;

CalculationControl * calcControl;
LEDDisplayControl * ledDisplayControl;
InterruptControl * intControl;
LEDControl * ledControl;

typedef struct
{
	Control * control;
} pthreadBundle;

static void * controlWrapper(void * bund)
{
	int privity_err;
	privity_err = ThreadCtl( _NTO_TCTL_IO, NULL );
	if ( privity_err == -1)
	{
		printf( "Can't get root permissions\n");
	}

	((pthreadBundle *) bund)->control->run();
	return NULL;
}

void startControlThreads()
{
	int i;
	int numControls = 4;

	ledDisplayControl = new LEDDisplayControl(context);
	intControl = new InterruptControl(context);
	ledControl = new LEDControl(context);
	calcControl = new CalculationControl(context);
	Control * controls[] = {ledDisplayControl, intControl, ledControl, calcControl};


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
	ThreadCtl( _NTO_TCTL_IO, NULL );

	if ( Control::ctrlHandle == MAP_DEVICE_FAILED ) {
		perror( "control map failed" );
	}
	if ( Control::inputHandle == MAP_DEVICE_FAILED ) {
		perror( "input map failed" );
	}
	if ( Control::outputAHandle == MAP_DEVICE_FAILED ) {
		perror( "output A map failed" );
	}
	if ( Control::outputBHandle == MAP_DEVICE_FAILED ) {
		perror( "output B map failed" );
	}
	if ( Control::interCtrlHandle == MAP_DEVICE_FAILED ) {
		perror( "interrupt control map failed" );
	}
	if ( Control::clearHandle == MAP_DEVICE_FAILED ) {
		perror( "interrupt clear map failed" );
	}

	//set IO direction
	out8(Control::ctrlHandle, CTRL_INIT);


}

int main(int argc, char *argv[]) {
	context = new StateContext();
	IOInit();
	startControlThreads();

	context->run();
}
