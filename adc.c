#include<msp430.h>

void init_adc()
{
	ADC10CTL0|=ADC10ON|SREF_0|ADC10SHT_2;
	ADC10CTL1|=INCH_6|SHS_0|ADC10DIV_0|ADC10SSEL_0|CONSEQ_0;
	ADC10AE0=BIT6;
	ADC10CTL0|=ENC;
}

void start()
{
	ADC10CTL0|=ADC10SC;
}

int busy()
{
	return ADC10CTL0 & ADC10BUSY;
}

void delay()
{
	int i=1000;
	while(i--);
}

main()
{
	init_adc();
	P1DIR=0x1;
	P1OUT=0x00;
	while(1)
	{
		start();
		while(busy());
		if(ADC10MEM<380)
			P1OUT=0x1;
		else
			P1OUT=0x00;
		delay();
	}
}
