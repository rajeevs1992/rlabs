#include<msp430.h>
#define MAX 400
void delay(int i)
{
	while(i--);
}
main()
{
	P1DIR=1;
	P1OUT=0;
	int i=0,c=1;
	while(1)
	{
		P1OUT=1;
		i=i+c;
		delay(i);
		P1OUT=0;
		delay(MAX-i);
		if(i==MAX)
			c=-1;
		else if(i==0)
			c=1;
	}
}

