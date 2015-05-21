#include "ComputeDistance.h"

ComputeDistance::ComputeDistance() : State()
{

}
void ComputeDistance::entryAction()
{
	ledDisplayControl->displayMode = DISTANCE;
}

void ComputeDistance::exitAction()
{

}

State* ComputeDistance::accept(StateEvent ev)
{
	if(ev == mode_pressed)
	{
		return new TimeElapsed();
	}
	else if(ev == set_pressed)
	{
		return new SetCircumference();
	}
}