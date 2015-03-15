
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
	int count = 0;

	while(true)
	{
		MsgReceive(timer.chid, &pulse, sizeof(pulse), NULL);
		if(MotorControl::motorUp && MotorControl::motorDown)
		{
			printf("ERROR: motorup and motordown\n");
		}
		else if(MotorControl::motorUp)
		{
			printf("Motor moving door up\n");
			count++;
			if(count >= 20)
			{
				context->queueEvent(door_open);
				count = 0;
				MotorControl::motorUp = false;
				MotorControl::motorDown = false;
				printf("Door Opened!\n");
			}
		}
		else if(MotorControl::motorDown)
		{
			printf("Motor moving door down\n");
			count++;
			if(count >= 20)
			{
				context->queueEvent(door_close);
				count = 0;
				MotorControl::motorUp = false;
				MotorControl::motorDown = false;
				printf("Door Closed!\n");
			}
		}
		else
		{
			//printf("Motor not doing anything\n");
		}
	}
}
