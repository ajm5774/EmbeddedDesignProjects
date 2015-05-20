#include "SetUnit.h"

SetUnit::SetUnit() : State()
{

}
void SetUnit::entryAction()
{

}

void SetUnit::exitAction()
{

}

State* SetUnit::accept(StateEvent ev)
{
	if(ev == set_pressed)
		return new SetCircumference();
	else if(ev == mode_pressed)
	{

	}

}
