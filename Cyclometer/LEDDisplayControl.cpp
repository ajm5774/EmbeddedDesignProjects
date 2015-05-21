
#include "LEDDisplayControl.h"
#include "CalculationControl.h"
#include "Cyclometer.h"

uint8_t LEDDisplayControl::segValues[] = {4,5,6,7};
bool LEDDisplayControl::showDP[] = {false,false,false,false};

LEDDisplayControl::LEDDisplayControl(): Control()
{
	//printf("LEDDisplayControl made");
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
		SetDisplayVals();
		Control::OUTPUTB = ConvertIntToDisplay(segValues[segment], showDP[segment]);

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
		SetDisplayDigits(getCalcC()->currentSpeed, 2, 0);
		SetDisplayDigits(getCalcC()->averageSpeed, 2, 2);
	}
	else if(displayMode == DISTANCE)
	{
		if(getCalcC()->unitMode == KPH)
			SetDisplayDigits(getCalcC()->distanceKM, 4, 0);
		else
			SetDisplayDigits(getCalcC()->distanceKM * getCalcC()->kmhToMph, 4, 0);
	}
	else if(displayMode == ELAPSED_TIME)
	{
		int seconds = ((int)(getCalcC()->elapsedMillis/1000)) % 60;
		int minutes = getCalcC()->elapsedMillis/1000/60;

		showDP[1] = true;

		SetDisplayDigits(seconds, 2, 0);
		SetDisplayDigits(minutes, 2, 2);
	}
	else
	{
		showDP[0] = false;
		showDP[1] = false;
		showDP[2] = false;
		showDP[3] = false;
	}


}

void LEDDisplayControl::SetDisplayDigits(float val, int numDigits, int startIndex)
{

	if(val < power(10.0, (double)numDigits-1))
	{
		showDP[NUMSEGS - startIndex-2] = true;
		segValues[NUMSEGS - startIndex - 1] = int(val*10) - int(val) * 10;
		SetDisplayDigits(int(val), numDigits, startIndex + 1);
	}
	else
	{
		showDP[NUMSEGS - startIndex-2] = false;
		SetDisplayDigits(int(val), numDigits, startIndex);
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
		segValues[NUMSEGS - 1 - (i + startIndex)] = val % (divisor*10)/divisor;
		divisor *= 10;
	}
}

double LEDDisplayControl::power(double num, double power)
{
	double ret = 1;
	int i;
	for(i = 0; i < power; i++)
	{
		ret *= num;
	}

	return ret;
}


uint8_t LEDDisplayControl::ConvertIntToDisplay(uint8_t digit, bool dp)
{
	uint8_t ret = 0;
	switch(digit)
	{
		case 0:
			ret = 0b11000000;
			break;
		case 1:
			ret =  0b11111001;
			break;
		case 2:
			ret =  0b10100100;
			break;
		case 3:
			ret =  0b10110000;
			break;
		case 4:
			ret =  0b10011001;
			break;
		case 5:
			ret =  0b10010010;
			break;
		case 6:
			ret =  0b10000010;
			break;
		case 7:
			ret =  0b11111000;
			break;
		case 8:
			ret =  0b10000000;
			break;
		case 9:
			ret =  0b10010000;
			break;
	}
	if(dp)
		ret = ret & 0b01111111;
	return ret;
}
