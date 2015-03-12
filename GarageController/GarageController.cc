#include <cstdlib>
#include <stdio.h>
#include <pthread.h>
#include "ConcurrentQueue.h"
#include "QueueItem.h"
#include "StateEvents.h"

pthread_t controlThreads[4];
pthread_t stateThread;

int main(int argc, char *argv[]) {
	ConcurrentQueue q;
	QueueItem item(RemotePressed);
	QueueItem item2(BeamInterrupt);

	printf("%d\n", q.count);

	q.enqueue(&item);
	q.enqueue(&item2);

	printf("%d\n", q.count);
	QueueItem * poppedItem = q.dequeue();
	printf("%d\n", q.count);
}

