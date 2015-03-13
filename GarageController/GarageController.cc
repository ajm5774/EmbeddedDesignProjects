#include <cstdlib>
#include <stdio.h>
#include <pthread.h>
#include "ConcurrentQueue.h"
#include "QueueItem.h"
#include "StateEvents.h"
#include "Control.h"
#include "IOControl.h"
#include "MotorControl.h"
#include "OvercurrentControl.h"
#include "BeamControl.h"
#include "StateContext.h"

pthread_t * threads[4];
StateContext context;

static void * controlWrapper(void * context)
{
	Control * c = (Control *)context;
	c->run();
	printf("what just happened");
}


void startControlThreads()
{
	int i;
	int numControls = 1;
	Control controls[] = {IOControl(context)};
	//controls[0] = IOControl(context);
	//controls[1] = MotorControl(context);
	//controls[2] = OverCurrentControl(context);
	//controls[3] = BeamControl(context);

	pthread_attr_t threadAttributes ;
	int policy ;
	struct sched_param parameters ;

	pthread_attr_init(&threadAttributes) ;		// initialize thread attributes structure -- must do before any other activity on this struct
	pthread_getschedparam(pthread_self(), &policy, &parameters) ;	// get this main thread's scheduler parameters
	parameters.sched_priority-- ;									// lower the priority
	pthread_attr_setschedparam(&threadAttributes, &parameters) ;	// set up the pthread_attr struct with the updated priority

	// now create the threads and pass along its thread number from the loop counter.
	for(i =0; i < numControls; i++)
	{
		pthread_create( threads[i], &threadAttributes, controlWrapper, (void *)&controls[0]);
	}
}

int main(int argc, char *argv[]) {
	context = StateContext();
	startControlThreads();
}


