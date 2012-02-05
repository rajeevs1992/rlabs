#include<msp430.h>
delay()
{
	int i=32000;
	while(i--);
}

main()
{
	P1DIR=0xf;
	while(1)
	{
		P1OUT=0x1;
		delay();
		P1OUT=0x2;
		delay();
		P1OUT=0x4;
		delay();
		P1OUT=0x8;
		delay();
	}
}


