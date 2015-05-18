#include <cstdlib>
#include <iostream>
#include <pthread.h>
#include <iostream>
#include <hw/inout.h>
#include "ConcurrentQueue.h"
#include "QueueItem.h"
#include "StateEvents.h"
#include "Control.h"
#include "StateContext.h"
#include <unistd.h>

const int numThreads = 4;
pthread_t * threads[numThreads];
StateContext * context;

typedef struct
{
	Control * control;
} pthreadBundle;

static void * controlWrapper(void * bund)
{
	ThreadCtl( _NTO_TCTL_IO, NULL );
	((pthreadBundle *) bund)->control->run();
	return NULL;
}

void startControlThreads()
{
	int i;
	int numControls = 2;

	Control * controls[] = {};


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

int main(int argc, char *argv[]) {
	context = new StateContext();
	startControlThreads();

	context->run();
}
