#include<msp430.h>
main()
{
	P1DIR=1 | BIT6;
	P1OUT=1|BIT6;
}
