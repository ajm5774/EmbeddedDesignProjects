#include "SetUnit.h"

SetUnit::SetUnit() : State()
{
	unitMode = KPH;
}
void SetUnit::entryAction()
{
	getLDC()->displayMode = SELECT_UNITS;
	getLDC()->SetDisplayDigits((int)unitMode, 4, 0);
}

void SetUnit::exitAction()
{

}

State* SetUnit::accept(StateEvent ev)
{
	if(ev == set_pressed)
	{
		getCalcC()->unitMode = unitMode;
		LEDControl::unitMode = unitMode;
		return new SetCircumference();
	}
	else if(ev == mode_pressed)
	{
		if(unitMode == KPH)
			unitMode = MPH;
		else
			unitMode = KPH;

		getLDC()->SetDisplayDigits((int)unitMode, 4, 0);
		return this;	
	}
	return this;
}
