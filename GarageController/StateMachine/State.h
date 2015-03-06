/*
 * State.h
 *
 *  Created on: Mar 6, 2015
 *      Author: ajm5774
 */

#ifndef STATE_H_
#define STATE_H_

class State
{
	string statusId;

public:
	void entryAction();
	void exitAction();
	void activity();
};

#endif /* STATE_H_ */
