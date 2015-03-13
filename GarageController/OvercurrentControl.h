/*
 * OvercurrentControl.h
 *
 *  Created on: Mar 6, 2015
 *      Author: ajm5774
 */

#ifndef OVERCURRENTCONTROL_H_
#define OVERCURRENTCONTROL_H_

class OverCurrentControl: public Control
{
public:
	StateContext context;
	OverCurrentControl();
	OverCurrentControl(StateContext context);
	void run();
	void setContext(StateContext context);
};

#endif /* OVERCURRENTCONTROL_H_ */
