/*
 * ConcurrentQueue.h
 *
 *  Created on: Mar 6, 2015
 *      Author: ajm5774
 */

#ifndef CONCURRENTQUEUE_H_
#define CONCURRENTQUEUE_H_

class ConcurrentQueue
{
	QueueItem * first;
	QueueItem * last;
	int count;

public:
	ConcurrentQueue();
	void enqueue(QueueItem * item);
	QueueItem * dequeue();
};

#endif /* CONCURRENTQUEUE_H_ */
