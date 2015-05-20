
#include "LEDControl.h"

bool LEDControl::wheelRotated = false;
bool LEDControl::wheelRotatedCleared = false;
bool LEDControl::isAutoMode = false;
Mode LEDControl::unitMode = KPH;

LEDControl::LEDControl(): Control()
{
	printf("LEDControl made");
}

LEDControl::LEDControl(StateContext * aContext): Control(aContext)
{
	context = aContext;
	CreateInterrupt(&timer, 750000, 0);//4 times a second
}

void LEDControl::run()
{
	struct _pulse pulse;
	startInterrupt(&timer);

	while(true)
	{
		MsgReceive(timer.chid, &pulse, sizeof(pulse), NULL);

		//WheelRotated LED
		if(wheelRotated && !wheelRotatedCleared)
		{
			setWheelRot(false);
			wheelRotatedCleared = true;//Set to make sure we stay off for .5s
			OUTPUTA = OUTPUTA | LED2_PIN_MASK;
		}
		else
		{
			wheelRotatedCleared = false;
			OUTPUTA = OUTPUTA & ~LED2_PIN_MASK;
		}

		//auto mode LED
		if(isAutoMode)
			OUTPUTA = OUTPUTA | LED1_PIN_MASK;
		else
			OUTPUTA = OUTPUTA & ~LED1_PIN_MASK;


		//units LED
		if(unitMode == MPH)
			OUTPUTA = OUTPUTA | LED3_PIN_MASK;
		else
			OUTPUTA = OUTPUTA & ~LED3_PIN_MASK;

		out8(outputAHandle, OUTPUTA);
	}
}

void LEDControl::setWheelRot(bool wheelRot)
{
	wheelRotated = wheelRot;
}
