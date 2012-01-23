#include<msp430.h>
main()
{
	P1DIR=0x41;
	P1OUT=0x40;
	TACTL=TASSEL_2|ID_0|MC_2|TAIE|TAIFG;
	while(1)
	{
		while(!(TACTL & 0x1));
		P1OUT^=0x41;
		TACTL=TACTL & ~0x1;
		TACTL|=ID_1;
	}
}

		


