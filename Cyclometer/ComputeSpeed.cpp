#include "ComputeSpeed.h"

ComputeSpeed::ComputeSpeed() : State()
{

}
void ComputeSpeed::entryAction()
{
	ledDisplayControl->displayMode = SPEED;
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
}
