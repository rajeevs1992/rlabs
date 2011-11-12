#include<msp430.h>
void delay()
{
	int i=32000;
	while(i--);
	return;
}
main()
{
	P1DIR=0x41;
	P1OUT=0x00;
	while(1)
	{
		while((P1IN & 0x08)==0x00)
		{
			P1OUT^=0x01;
			delay();
			delay();
			P1OUT^=0x40;
		}
		while((P1IN & 0x08)!=0)
		{
			P1OUT^=0x41;
			delay();
			delay();
			P1OUT^=0x00;
		}
	}
}
