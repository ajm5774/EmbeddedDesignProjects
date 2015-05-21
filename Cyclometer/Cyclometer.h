/*
 * Cyclometer.h
 *
 *  Created on: May 20, 2015
 *      Author: ajm5774
 */

#ifndef CYCLOMETER_H_
#define CYCLOMETER_H_

#include "LEDDisplayControl.h"
#include "CalculationControl.h"


//CalculationControl * calcControl;
//InterruptControl * intControl;
//LEDControl * ledControl;
//LEDDisplayControl * ledDisplayControl;

LEDDisplayControl * getLDC();
CalculationControl * getCalcC();

void resetSystem();

#endif /* CYCLOMETER_H_ */
