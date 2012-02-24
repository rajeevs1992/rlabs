#include<msp430.h>
__attribute__((interrupt(WDT_VECTOR)))
void isr()
{
	P1OUT^=0x41;
}

void init()
{
	WDTCTL=WDTPW | WDTTMSEL ;
	IE1=WDTIE;
}

main()

{
	
	P1DIR=0x41;
	P1OUT=0x01;
	__enable_interrupt();
	init();
	while(1);
}
