
#include "InterruptControl.h"

uintptr_t InterruptControl::interCtrlHandle = mmap_device_io( PORT_LENGTH, DAQ_INTER_CTRL );
uintptr_t InterruptControl::clearHandle = mmap_device_io(PORT_LENGTH, DAQ_CLEAR);

InterruptControl::InterruptControl(): Control()
{
	printf("InterruptControl made");
}

InterruptControl::InterruptControl(StateContext * aContext): Control(aContext)
{
	context = aContext;

	waitTimeMicros = 200000;
	CreateInterrupt(&timer, waitTimeMicros, 0);//5 times a second

	int privity_err;
	privity_err = ThreadCtl( _NTO_TCTL_IO, NULL );
	if ( privity_err == -1)
	{
		printf( "Can't get root permissions\n");
	}

	if (interCtrlHandle == MAP_DEVICE_FAILED ) {
		perror( "interrupt control map failed" );
	}
	if (clearHandle == MAP_DEVICE_FAILED ) {
		perror( "interrupt clear map failed" );
	}

	_pulseHist = 0;
	awaitingReset = false;
	awaitingResetVals = false;
	waitCount = 0;
	modeHeldWaitCount = 0;
	b3Triggered = false;

}

void InterruptControl::run()
{
	out8( interCtrlHandle, INIT_BIT );
	out8( clearHandle, CLEAR );

	_interruptID = InterruptAttach(DIO_IRQ, interruptReceived, this, sizeof(this), 0);
	if (_interruptID == -1) {
		fprintf(stderr, "can't attach to IRQ %d\n", DIO_IRQ);
		perror(NULL);
	}

	struct _pulse pulse;
	startInterrupt(&timer);

	bool b1Pressed = false;
	bool b2Pressed = false;
	bool b3Pressed = false;

	bool b1BeenPressed = false;
	bool b2BeenPressed = false;
	bool b3BeenPressed = false;

	for(;;){
		MsgReceive(timer.chid, &pulse, sizeof(pulse), NULL);

		//interrupt stuff
		if (_pulseCount != _pulseHist)
		{
			_pulseHist = _pulseCount;
			if(getCalcC()->bPerformCalcs)
			{
				getCalcC()->addNumRots(_pulseCount);
			}
			context->queueEvent(wheel_rotated);
		}
		_pulseCount = 0;

		//Buttons
		lastInput = input;
		input = in8(inputHandle);

		b1Pressed = isButton1Pressed(input);
		b2Pressed = isButton2Pressed(input);
		b3Pressed = isButton3Pressed(input);

		b1BeenPressed = button1BeenPressed(lastInput);//set
		b2BeenPressed = button2BeenPressed(lastInput);//startstop
		b3BeenPressed = button3BeenPressed(lastInput);//mode

		//all 3 buttons down - check reset
		if(b1Pressed && b2Pressed && b3Pressed)
		{
			if(!awaitingReset)
				waitCount = 0;
			waitCount++;
			awaitingReset = true;

			//reset if they have been down for 2 seconds
			if((waitCount * waitTimeMicros) >= 2000000)
			{
				context->queueEvent(reset);
				waitCount = 0;
			}
		}
		//mode + start/stop pressed
		else if(b2Pressed && b3Pressed)
		{
			if(!awaitingResetVals)
				waitCount = 0;
			waitCount++;
			awaitingResetVals = true;

			//reset if they have been down for 2 seconds
			if((waitCount * waitTimeMicros) >= 2000000)
			{
				//TODO reset trip vals
				printf("reset trip values");
				waitCount = 0;
			}
		}
		else if(b1Pressed)
		{
			if(!b1BeenPressed)
				waitCount = 0;
			else if(waitCount * waitTimeMicros >= 200000)
				context->queueEvent(set_pressed);
			waitCount++;
		}
		else if(b2Pressed)
		{
			if(!b2BeenPressed)
				waitCount = 0;
			else if(waitCount * waitTimeMicros >= 200000)
				context->queueEvent(stop_start_pressed);
			waitCount++;
		}
		else if(b3Pressed)
		{
			if(!b3BeenPressed)
				waitCount = 0;
			else if (waitCount * waitTimeMicros >= 2000000)//2sec
			{
				modeHeldWaitCount++;
				if(modeHeldWaitCount * waitTimeMicros >= 1000000)//1 sec
				{
					context->queueEvent(increment_tire_size);
					modeHeldWaitCount = 0;
				}
			}
			else if(waitCount * waitTimeMicros >= 200000 &&
					!b3Triggered)//.2sec
			{
				context->queueEvent(mode_pressed);
				b3Triggered = true;
			}
			waitCount++;
		}
		else
		{
			//detect quick button presses
			if(waitCount * waitTimeMicros <= 200000)
			{
				if(b1BeenPressed)
				{
					context->queueEvent(set_pressed);
				}
				else if(b2BeenPressed)
				{
					context->queueEvent(stop_start_pressed);
				}
				else if(b3BeenPressed)
					context->queueEvent(mode_pressed);
			}
			awaitingReset = false;
			awaitingResetVals = false;
			waitCount = 0;
			modeHeldWaitCount = 0;
			b3Triggered = false;
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

bool InterruptControl::button1BeenPressed(uint8_t lastInput)
{
	return lastInput & BOTTON1_PIN_MASK;
}

bool InterruptControl::button2BeenPressed(uint8_t lastInput)
{
	return lastInput & BOTTON2_PIN_MASK;
}

bool InterruptControl::button3BeenPressed(uint8_t lastInput)
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
	out8(InterruptControl::clearHandle, CLEAR );
	return NULL;
}
