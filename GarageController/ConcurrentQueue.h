/*
 * ConcurrentQueue.h
 *
 *  Created on: Mar 6, 2015
 *      Author: ajm5774
 */

#ifndef CONCURRENTQUEUE_H_
#define CONCURRENTQUEUE_H_

#include "QueueItem.h"
#include "ConcurrentQueue.h"

class ConcurrentQueue
{
public:
	ConcurrentQueue();
	void enqueue(QueueItem * item);
	QueueItem * dequeue();
	int count;

private:
	QueueItem * first;
	QueueItem * last;
};

#endif /* CONCURRENTQUEUE_H_ */
