
#include "InterruptControl.h"

InterruptControl::InterruptControl(): Control()
{
	printf("InterruptControl made");
}

InterruptControl::InterruptControl(StateContext * aContext): Control(aContext)
{
	context = aContext;
	CreateInterrupt(&timer, 200000, 0);//5 times a second

	out8( interCtrlHandle, INIT_BIT );
	out8( clearHandle, CLEAR );

	_pulseHist = 0;
}

void InterruptControl::run()
{
	_interruptID = InterruptAttach(DIO_IRQ, interruptReceived, this, sizeof(this), 0);
	if (_interruptID == -1) {
		fprintf(stderr, "can't attach to IRQ %d\n", DIO_IRQ);
		perror(NULL);
	}

	struct _pulse pulse;
	startInterrupt(&timer);

	for(;;){
		MsgReceive(timer.chid, &pulse, sizeof(pulse), NULL);

		//interrupt stuff
		if (_pulseCount != _pulseHist)
		{
			_pulseHist = _pulseCount;
		}
		_pulseCount = 0;

		//Buttons
		lastInput = input;
		input = in8(inputHandle);

		if(lastInput != input)
		{
			if((input & FULL_OPEN_PIN_MASK) &&
					!(lastInput & FULL_OPEN_PIN_MASK))
				event = door_open;
			if((input & FULL_CLOSED_PIN_MASK) &&
					!(lastInput & FULL_CLOSED_PIN_MASK))
				event = door_close;
			if((input & IR_BROKEN_PIN_MASK) &&
					!(lastInput & IR_BROKEN_PIN_MASK))
				event = beam_interrupt;
		}
	}
}

bool InterruptControl::isButton1Pressed(uint8_t input){
	return input & BOTTON1_PIN_MASK;
}
bool InterruptControl::isButton2Pressed(uint8_t input){
	return input & BOTTON2_PIN_MASK;
}
bool InterruptControl::isButton3Pressed(uint8_t input){
	return input & BOTTON3_PIN_MASK;
}

bool Interruptcontrol::button1BeenPressed(uint8_t lastInput)
{
	return lastInput & BOTTON1_PIN_MASK;
}

bool Interruptcontrol::button2BeenPressed(uint8_t lastInput)
{
	return lastInput & BOTTON2_PIN_MASK;
}

bool Interruptcontrol::button3BeenPressed(uint8_t lastInput)
{
	return lastInput & BOTTON3_PIN_MASK;
}









int InterruptControl::getCount()
{
	return _pulseHist;
}

void InterruptControl::updateCount()
{
	_pulseCount++;
}

const struct sigevent * interruptReceived(void *arg, int id)
{
	((InterruptControl *)arg)->updateCount();
	out8( Control::clearHandle, CLEAR );
	return NULL;
}
