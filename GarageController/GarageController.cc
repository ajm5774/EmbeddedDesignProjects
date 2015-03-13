#include <cstdlib>
#include <stdio.h>
#include <pthread.h>
#include "ConcurrentQueue.h"
#include "QueueItem.h"
#include "StateEvents.h"
#include "Control.h"
#include "IOControl.h"
#include "MotorControl.h"


Control controls[4];

int main(int argc, char *argv[]) {
	StateContext context = new StateContext();
	controls[0] = new IOControl(NULL);
	controls[0] = new IOControl(NULL);
}

void startControlThreads()
{
	pthread_attr_t threadAttributes ;
	int v = 0;
	int policy ;
	struct sched_param parameters ;

	pthread_attr_init(&threadAttributes) ;		// initialize thread attributes structure -- must do before any other activity on this struct
	pthread_getschedparam(pthread_self(), &policy, &parameters) ;	// get this main thread's scheduler parameters
	parameters.sched_priority-- ;									// lower the priority
	pthread_attr_setschedparam(&threadAttributes, &parameters) ;	// set up the pthread_attr struct with the updated priority

	// now create the threads and pass along its thread number from the loop counter.
	pthread_create( &thread, &threadAttributes, &run, &v);
}
