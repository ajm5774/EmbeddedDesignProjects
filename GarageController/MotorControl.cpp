
#include "MotorControl.h"

bool MotorControl::motorUp = false;
bool MotorControl::motorDown = false;

MotorControl::MotorControl(StateContext * aContext)
{
	context = aContext;
}

void MotorControl::run()
{
}
