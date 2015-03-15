
#include "MotorControl.h"

bool MotorControl::motorUp = false;
bool MotorControl::motorDown = false;

MotorControl::MotorControl(): Control()
{
	printf("MotorControl made");
}

MotorControl::MotorControl(StateContext * aContext): Control(aContext)
{
	context = aContext;
	CreateInterrupt(&timer, 500000, 0);//2 times a second
}

void MotorControl::run()
{
	struct _pulse pulse;
	startInterrupt(&timer);

	while(true)
	{
		MsgReceive(timer.chid, &pulse, sizeof(pulse), NULL);
		if(motorUp && motorDown)
		{
			printf("ERROR: motorup and motordown\n");
		}
		else if(motorUp)
		{
			printf("Motor moving door up\n");
		}
		else if(motorDown)
		{
			printf("Motor moving door down\n");
		}
		else
		{
			//printf("Motor not doing anything\n");
		}
	}
}
