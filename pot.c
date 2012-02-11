#include<msp430.h>

void init_adc()
{
	ADC10CTL0|=ADC10ON|SREF_0|ADC10SHT_2;
	ADC10CTL1|=INCH_4|SHS_0|ADC10DIV_0|ADC10SSEL_0|CONSEQ_0;
	ADC10AE0=BIT4;
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
/*Potentiometer used is 50k as the 10k is very small in size and hence difficult to handle.
Green LED if BIT4<1V
Red LED if BIT4<2V
Both LED if BIT4>2V*/
	init_adc();
	P1DIR=0x41;
	P1OUT=0x00;
	while(1)
	{
		start();
		while(busy());
		if(ADC10MEM<284)
			P1OUT=0x40;
		else if(ADC10MEM<568)
			P1OUT=0x1;
		else
			P1OUT=0x41;
		delay();
	}
}
