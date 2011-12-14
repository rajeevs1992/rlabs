#include<msp430.h>
main()
{
	P1DIR=0x41;
	while((P1IN>>3) &1);
		while(!(P1IN>>3)&1)
			P1OUT=0x01;
	P1OUT=0x40;
}
