#include <stdio.h>
#include <assert.h>
#include <pthread.h>

#include "ConcurrentQueue.h"

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

ConcurrentQueue:: ConcurrentQueue(){}

void ConcurrentQueue::enqueue(QueueItem * qItem)
{
	pthread_mutex_lock(&mutex);
	if (count == 0)
	{
		first = qItem;
		last = qItem;
	}
	else {
		last->behind = qItem;
		last = qItem;
	}
	count++;

	pthread_mutex_unlock(&mutex);
}
QueueItem * ConcurrentQueue::dequeue()
{
	QueueItem * qItem = 0;
	pthread_mutex_lock(&mutex);
	if(count == 0)
	{
		pthread_mutex_unlock(&mutex);
		return qItem;
	}
	else if (count == 1)
	{
		qItem = first;
		first = 0;
		last = 0;
	}
	else {
		qItem = first;
		first = first->behind;
	}
	count--;
	pthread_mutex_unlock(&mutex);
	return cust;
}
