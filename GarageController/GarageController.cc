#include <cstdlib>
#include <iostream>
#include "ConcurrentQueue.h"
#include "StateEvents.h"

int main(int argc, char *argv[]) {
	ConcurrentQueue q;
	QueueItem * item(RemotePressed);
	QueueItem * item2(BeamInterrupt);

	q.enqueue(item);
	q.enqueue(item2);

	QueueItem * poppedItem = q.dequeue();
	printf(poppedItem);
}
