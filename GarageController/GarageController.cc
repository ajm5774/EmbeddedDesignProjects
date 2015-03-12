#include <cstdlib>
#include <stdio.h>
#include "ConcurrentQueue.h"
#include "QueueItem.h"
#include "StateEvents.h"

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
