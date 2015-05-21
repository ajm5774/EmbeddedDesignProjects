#include "SetUnit.h"

SetUnit::SetUnit() : State()
{
	unitMode = KPH;
}
void SetUnit::entryAction()
{
	ledDisplayControl->displayMode = SELECT_UNITS;
	ledDisplayControl->SetDisplayDigits((int)unitMode, 4, 0);
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
		if(unitMode == KPH)
			unitMode = MPH;
		else
			unitMode = KPH;

		ledDisplayControl->SetDisplayDigits((int)unitMode, 4, 0);
		return this;	
	}
	return this;
}
