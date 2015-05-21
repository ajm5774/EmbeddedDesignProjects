
#include "LEDDisplayControl.h"

uint8_t LEDDisplayControl::segValues[] = {4,5,6,7};
bool showDP[] = {false,false,false,false};

LEDDisplayControl::LEDDisplayControl(): Control()
{
	printf("LEDDisplayControl made");
}

LEDDisplayControl::LEDDisplayControl(StateContext * aContext): Control(aContext)
{
	context = aContext;
	CreateInterrupt(&timer, 7000, 0);//20 times a second
	displayMode = SELECT_UNITS;
}

void LEDDisplayControl::run()
{
	struct _pulse pulse;
	startInterrupt(&timer);
	int segment = 0;

	while(true)
	{
		MsgReceive(timer.chid, &pulse, sizeof(pulse), NULL);
		Control::OUTPUTB = ConvertIntToDisplay(segValues[segment]);

		if(segment == 0)
			Control::OUTPUTA = (Control::OUTPUTA  & 0x10) | ANODE1_PIN_MASK;
		else if(segment == 1)
			Control::OUTPUTA = (Control::OUTPUTA  & 0x10) | ANODE2_PIN_MASK;
		else if(segment == 2)
			Control::OUTPUTA = (Control::OUTPUTA  & 0x10) | ANODE3_PIN_MASK;
		else if(segment == 3)
			Control::OUTPUTA = (Control::OUTPUTA  & 0x10) | ANODE4_PIN_MASK;

		out8( Control::outputAHandle, Control::OUTPUTA );
		out8( Control::outputBHandle, OUTPUTB );

		segment++;
		segment %= NUMSEGS;
	}
}

void LEDDisplayControl::SetDisplayVals()
{
	if(displayMode == SPEED)
	{
		SetDisplayDigits(calcControl->currentSpeed, 2, 0);
		SetDisplayDigits(calcControl->averageSpeed, 2, 2);
	}
	else if(displayMode == DISTANCE)
	{
		if(calcControl->unitMode == KMH)
			SetDisplayDigits(calcControl->distanceKM, 4, 0);
		else
			SetDisplayDigits(calcControl->distanceKM * kmhToMph, 4, 0);
	}
	else if(displayMode == ELAPSED_TIME)
	{
		int seconds = calcControl->elapsedMillis/1000 % 60;
		int minutes = calcControl->elapsedMillis/1000/60;

		SetDisplayDigits(seconds, 2, 0);
		SetDisplayDigits(minutes, 2, 2);
	}

	//moved this to the states
	/*else if(displayMode == SELECT_UNITS)
	{
		SetDisplayDigits((int)(calcControl->unitMode), 4, 0);
	}
	else if(displayMode == SELECT_TIRE_SIZE)
	{
		SetDisplayDigits(wheelCircumCM, 4, 0);
	}*/
}

void LEDDisplayControl::SetDisplayDigits(float val, int numDigits, int startIndex)
{
	if(val < pow(10, numDigits))
	{
		segValues[startIndex] = int(val*10) - int(val) * 10;
		SetDisplayDigits(int(val), numDigits, startIndex + 1);
	}
	else
	{
		SetDisplayDigits(int(val), numDigits, )
	}
}

void LEDDisplayControl::SetDisplayDigits(int val, int numDigits, int startIndex)
{
	//limit the inputs
	if(numDigits + startIndex > 4)
		numDigits = 4 - startIndex;

	val = val%1000;//max value of 999
	
	int i;
	int divisor = 1;
	for(i = 0; i < numDigits; i++)
	{
		segValues[i + startIndex] = val % (divisor*10)/divisor;
		divisor *= 10;
	}
}



uint8_t LEDDisplayControl::ConvertIntToDisplay(uint8_t digit)
{
	switch(digit)
	{
		case 0:
			return 0b11000000;
			break;
		case 1:
			return 0b11111001;
			break;
		case 2:
			return 0b10100100;
			break;
		case 3:
			return 0b10110000;
			break;
		case 4:
			return 0b10011001;
			break;
		case 5:
			return 0b10010010;
			break;
		case 6:
			return 0b10000010;
			break;
		case 7:
			return 0b11111000;
			break;
		case 8:
			return 0b10000000;
			break;
		case 9:
			return 0b10010000;
			break;
	}
	return digit;
}
