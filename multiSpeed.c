#include<msp430.h>
void main()
{
	P1DIR=0x41;
	TACTL=0x0222;
	P1OUT=0x01;
	while(1)
	{
		while(!(TACTL & 0x1));
		P1OUT^=0x41;
		TACTL=0x0262;
	}
}
