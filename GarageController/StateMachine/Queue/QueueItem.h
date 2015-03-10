/*
 * QueueItem.h
 *
 *  Created on: Mar 6, 2015
 *      Author: ajm5774
 */

#ifndef QUEUEITEM_H_
#define QUEUEITEM_H_

template <class T>
class QueueItem
{
public:
	QueueItem(T* value);
	T * value;
	T * behind;
};

#endif /* QUEUEITEM_H_ */
