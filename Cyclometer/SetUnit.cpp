#include "SetUnit.h"

SetUnit::SetUnit() : State()
{
	unitMode = KMH;
}
void SetUnit::entryAction()
{
	ledDisplayControl->displayMode = SELECT_UNITS;
}

void SetUnit::exitAction()
{

}

State* SetUnit::accept(StateEvent ev)
{
	if(ev == set_pressed)
	{
		calcControl->unitMode = unitMode;
		LEDControl::unitMode = unitMode;
		return new SetCircumference();
	}
	else if(ev == mode_pressed)
	{
		if(unitMode == KMH)
			unitMode = MPH;
		else
			unitMode = KMH;

		ledDisplayControl->ledSetDisplayDigits((int)unitMode, 4, 0);
		return this;	
	}

}
