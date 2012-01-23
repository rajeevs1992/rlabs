#include<msp430.h>
volatile int count = 0;
__attribute__((interrupt(TIMERA1_VECTOR)))
timer_isr()
{
	count++;
	TACTL&=~TAIFG;
}

main()
{
	P1DIR=0X01;
	P1OUT=0x00;
	TACTL=TASSEL_2|ID_3|MC_2|TAIE;
	__enable_interrupt();
	while(count<5);
	P1OUT=0x01;
}
	
