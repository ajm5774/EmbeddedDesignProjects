#include "SetCircumference.h"

SetCircumference::SetCircumference() : State()
{
	tireCircumCM = 210;//210 is tire starting value
}
void SetCircumference::entryAction()
{
	ledDisplayControl->displayMode = SELECT_TIRE_SIZE;
	ledDisplayControl->ledSetDisplayDigits(tireCircumCM, 4, 0);
}

void SetCircumference::exitAction()
{

}

State* SetCircumference::accept(StateEvent ev)
{
	if(ev == set_pressed)
	{
		calcControl->wheelCircumCM = tireCircumCM;
		calcControl->bPerformCalcs = true;
		return new ComputeSpeed();
	}
	else if(ev == mode_pressed || ev == increment_tire_size)
	{
		tireCircumCM++;

		if(tireCircumCM > 220)//220 is max size
			tireCircumCM = 190;//minimum is 190

		ledDisplayControl->ledSetDisplayDigits(tireCircumCM, 4, 0);
		return this;	
	}
}
