#include<msp430.h>
__attribute__((interrupt(TIMERA1_VECTOR)))
timer_isr()
{
	P1OUT^=BIT0;
	TACTL&=~TAIFG;
}
main()
{
	P1DIR=0x41;
	P1OUT=0x01;
	TACTL=TASSEL_2|ID_0|MC_2|TAIFG;
	__enable_interrupt();
	while(1);
}

		


