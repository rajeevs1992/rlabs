#include<msp430.h>
main()
{
	P1DIR=0x41;
	P1OUT=0x01;
	TACTL=0x222;
	while(1)
	{
		while(!(TACTL & 0x1));
		P1OUT^=0x01;
		TACTL=TACTL & ~0x1;
	}
}

		


