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
	stop_start_pressed = 1,
	set_pressed = 2,
	mode_pressed = 3,
	reset = 4,
	wheel_rotated = 5
};

#endif /* STATEEVENTS_H_ */
