
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
		if(MotorControl::motorUp)
		{
			OUTPUT = OUTPUT | 1 << MOTOR_UP_PIN;
			out8(DAQ_OUTPUT, OUTPUT);
		}
		else
		{
			OUTPUT = OUTPUT | 0 << MOTOR_UP_PIN;
		}

		if(MotorControl::motorDown)
		{
			OUTPUT = OUTPUT | 1 << MOTOR_DOWN_PIN;
			out8(DAQ_OUTPUT, OUTPUT);
		}
		else
		{
			OUTPUT = OUTPUT | 0 << MOTOR_DOWN_PIN;
		}
	}
}
