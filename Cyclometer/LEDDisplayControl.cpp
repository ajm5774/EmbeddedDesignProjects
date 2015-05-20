
#include "LEDDisplayControl.h"

uint8_t LEDDisplayControl::segValues[] = {4,5,6,7};

LEDDisplayControl::LEDDisplayControl(): Control()
{
	printf("LEDDisplayControl made");
}

LEDDisplayControl::LEDDisplayControl(StateContext * aContext): Control(aContext)
{
	context = aContext;
	CreateInterrupt(&timer, 50000, 0);//20 times a second
}

void LEDDisplayControl::run()
{
	struct _pulse pulse;
	startInterrupt(&timer);
	int segment = 0;
	while(true)
	{
		Control::OUTPUTB = ConvertIntToDisplay(segValues[segment]);

		if(segment == 0)
			Control::OUTPUTA = (Control::OUTPUTA  & 0x10) | ANODE1_PIN_MASK;
		else if(segment == 1)
			Control::OUTPUTA = (Control::OUTPUTA  & 0x10) | ANODE2_PIN_MASK;
		else if(segment == 2)
			Control::OUTPUTA = (Control::OUTPUTA  & 0x10) | ANODE3_PIN_MASK;
		else if(segment == 3)
			Control::OUTPUTA = (Control::OUTPUTA  & 0x10) | ANODE4_PIN_MASK;

		//printf("%d - %d\n", Control::OUTPUTA, Control::OUTPUTB);
		out8( Control::outputAHandle, Control::OUTPUTA );
		out8( Control::outputBHandle, OUTPUTB );

		usleep(10000);

		segment++;
		segment %= NUMSEGS;
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
