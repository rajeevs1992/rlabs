#include<msp430.h>
main()
{
	P1DIR=0x41;
	while(1)
		if((P1IN & 0x08) == 0x00)
			P1OUT=0x01;
		else
			P1OUT=0x40;
}
