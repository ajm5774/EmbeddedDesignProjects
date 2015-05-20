
#include "InterruptControl.h"

InterruptControl::InterruptControl(): Control()
{
	printf("InterruptControl made");
}

InterruptControl::InterruptControl(StateContext * aContext): Control(aContext)
{
	context = aContext;
	CreateInterrupt(&timer, 200000, 0);//2 times a second

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
		if (_pulseCount != _pulseHist)
		{
			_pulseHist = _pulseCount;
		}
		_pulseCount = 0;
	}
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
