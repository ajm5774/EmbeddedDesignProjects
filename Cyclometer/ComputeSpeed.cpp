#include "ComputeSpeed.h"

ComputeSpeed::ComputeSpeed() : State()
{

}
void ComputeSpeed::entryAction()
{
	getLDC()->displayMode = SPEED;
}

void ComputeSpeed::exitAction()
{

}

State* ComputeSpeed::accept(StateEvent ev)
{
	if(ev == mode_pressed)
	{
		return new ComputeDistance();
	}
	return this;
}
