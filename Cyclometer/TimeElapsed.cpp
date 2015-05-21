#include "TimeElapsed.h"

TimeElapsed::TimeElapsed() : State()
{

}
void TimeElapsed::entryAction()
{
	ledDisplayControl->displayMode = ELAPSED_TIME;
}

void TimeElapsed::exitAction()
{

}

State* TimeElapsed::accept(StateEvent ev)
{
	if(ev == mode_pressed)
	{
		return new ComputeSpeed();
	}
	return this;
}
