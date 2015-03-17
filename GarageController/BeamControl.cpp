
#include "BeamControl.h"

bool BeamControl::beamOn = false;

BeamControl::BeamControl(): Control()
{
	printf("BeamControl made");
}

BeamControl::BeamControl(StateContext * aContext): Control(aContext)
{
	context = aContext;
	CreateInterrupt(&timer, 0, 1);//every second
}

void BeamControl::run()
{
	struct _pulse pulse;
	startInterrupt(&timer);

	while(true)
	{
		MsgReceive(timer.chid, &pulse, sizeof(pulse), NULL);
		if(BeamControl::beamOn)
		{
			printf("Beam is on! \n");
		}
	}
}
