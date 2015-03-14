#include <cstdlib>
#include <stdio.h>
#include <pthread.h>
#include "ConcurrentQueue.h"
#include "QueueItem.h"
#include "StateEvents.h"
#include "IOControl.h"
#include "MotorControl.h"
#include "OvercurrentControl.h"
#include "BeamControl.h"
#include "StateContext.h"

const int numThreads = 4;
pthread_t * threads[numThreads];
StateContext context;

typedef struct
{
	int controlNum;
	StateContext * context;
} pthreadBundle;

static void * controlWrapper(void * bund)
{
	int controlNum = ((pthreadBundle *)bund)->controlNum;
	StateContext * context = ((pthreadBundle *)bund)->context;

	//this is ugly, but there isn't a better way to do this
	//since pthread can only pass void * params and control is
	//a generic type.
	if(controlNum == 0)
	{
			IOControl * io = new IOControl(context);
			io->run();
	}

	return NULL;
}

void startControlThreads()
{
	pthread_attr_t threadAttributes ;
	int policy ;
	int i = 0;;
	int numControls = 1;
	struct sched_param parameters ;

	pthread_attr_init(&threadAttributes) ;		// initialize thread attributes structure -- must do before any other activity on this struct
	pthread_getschedparam(pthread_self(), &policy, &parameters) ;	// get this main thread's scheduler parameters
	parameters.sched_priority-- ;									// lower the priority
	pthread_attr_setschedparam(&threadAttributes, &parameters) ;	// set up the pthread_attr struct with the updated priority

	// now create the threads and pass along its thread number from the loop counter
	pthreadBundle bundle = {i, &context};
	for(i = 0; i < numControls; i++)
	{
		bundle.controlNum = i;
		pthread_create( threads[0], &threadAttributes, controlWrapper, (void *)&bundle);
	}
}

int main(int argc, char *argv[]) {
	context = StateContext();
	startControlThreads();

	int i;
	for(i = 0; i < numThreads; i++)
	{
		pthread_join(*threads[i], 0);
	}
}


