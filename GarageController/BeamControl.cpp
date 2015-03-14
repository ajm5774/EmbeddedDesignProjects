
#include "BeamControl.h"

bool BeamControl::beamOn = false;

BeamControl::BeamControl(StateContext * aContext)
{
	context = aContext;
}

void BeamControl::run()
{
}
