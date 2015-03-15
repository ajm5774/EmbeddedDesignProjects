/*
 * State.h
 *
 *  Created on: Mar 6, 2015
 *      Author: ajm5774
 */

#ifndef STATE_H_
#define STATE_H_

#include <string>
using namespace std;

class State
{
public:
	//string statusId;
	State();
	virtual std::string getStatusId();
	virtual void entryAction();
	virtual void exitAction();
	//bool operator<(const State& state1) const { return this.getStatusId() < state1.getStatusId();}

};

#endif /* STATE_H_ */
