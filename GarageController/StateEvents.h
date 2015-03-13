/*
 * StateEvents.h
 *
 *  Created on: Mar 6, 2015
 *      Author: ajm5774
 */

#ifndef STATEEVENTS_H_
#define STATEEVENTS_H_


enum StateEvent
{
	remote_pressed,
	beam_interrupt,
	motor_overcurrent,
	door_close,
	door_open
};

#endif /* STATEEVENTS_H_ */
