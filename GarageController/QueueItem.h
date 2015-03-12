/*
 * QueueItem.h
 *
 *  Created on: Mar 6, 2015
 *      Author: ajm5774
 */

#ifndef QUEUEITEM_H_
#define QUEUEITEM_H_

#include "StateEvents.h"

class QueueItem
{
public:
	QueueItem(StateEvent event);
	StateEvent event;
	QueueItem * behind;
};

#endif /* QUEUEITEM_H_ */
