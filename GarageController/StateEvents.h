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
	invalid = 0,
	remote_pressed = 1,
	beam_interrupt =2,
	motor_overcurrent = 3,
	door_close = 4,
	door_open = 5,

};

#endif /* STATEEVENTS_H_ */
