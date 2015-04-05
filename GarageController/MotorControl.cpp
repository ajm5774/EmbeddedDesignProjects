
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
	CreateInterrupt(&timer, 200000, 0);//2 times a second
}

void MotorControl::run()
{
	struct _pulse pulse;
	startInterrupt(&timer);

	while(true)
	{
		MsgReceive(timer.chid, &pulse, sizeof(pulse), NULL);
		if(MotorControl::motorUp)
			OUTPUT = OUTPUT | MOTOR_UP_PIN_MASK;
		else
			OUTPUT = OUTPUT & 0xFE;

		if(MotorControl::motorDown)
		{
			OUTPUT = OUTPUT | MOTOR_DOWN_PIN_MASK;
			OUTPUT = OUTPUT | IR_BEAM_ON_MASK;
		}
		else
			OUTPUT = OUTPUT & 0xF9;

		out8(DAQ_OUTPUT, OUTPUT);
	}
}
