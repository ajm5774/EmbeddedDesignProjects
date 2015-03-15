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
#include <unistd.h>

const int numThreads = 4;
pthread_t * threads[numThreads];
StateContext context;

/*typedef struct
{
	int * controlNum;
	StateContext * context;
} pthreadBundle;

static void * controlWrapper(void * bund)
{
	int controlNum = *(((pthreadBundle *)bund)->controlNum);
	StateContext * context = ((pthreadBundle *)bund)->context;

	//this is ugly, but there isn't a better way to do this
	//Decendants of Control run Control::run due to casting,
	//pthread requires void * so a cast is necessary...
	if(controlNum == 0)
	{
		IOControl * io = new IOControl(context);
		io->run();
	}

	return NULL;
}
*/

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
	IOControl * io = new IOControl(&context);
	MotorControl * mc = new MotorControl(&context);
	OverCurrentControl * occ = new OverCurrentControl(&context);
	BeamControl * bc = new BeamControl(&context);
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

int main(int argc, char *argv[]) {
	context = StateContext();

	startControlThreads();

	while(true)
	{
		sleep(2000);
	}

	pthread_join(*threads[0], 0);
	pthread_join(*threads[1], 0);
	pthread_join(*threads[2], 0);
	pthread_join(*threads[3], 0);
}


