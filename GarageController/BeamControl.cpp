
#include "BeamControl.h"

bool BeamControl::beamOn = false;

BeamControl::BeamControl(): Control()
{
	printf("BeamControl made");
}

BeamControl::BeamControl(StateContext * aContext): Control(aContext)
{
	context = aContext;
	CreateInterrupt(&timer, 500000, 0);//2 times a second
}

void BeamControl::run()
{
	struct _pulse pulse;
	startInterrupt(&timer);

	while(true)
	{
		MsgReceive(timer.chid, &pulse, sizeof(pulse), NULL);
		if(beamOn)
		{
			printf("Beam is on! \n");
		}
		else
		{
			//printf("Beam is off! \n");
		}
	}
}
