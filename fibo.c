#include<msp430.h>
main()
{
	P1DIR=0x41;
	P1OUT=0x40;
	int lfsr = 0xace1;
	unsigned bit;
	TACTL=TASSEL_2|ID_0|MC_2|TAIFG;
	do 
	{
	   bit =(((lfsr>>15 ^ lfsr>>13) ^ lfsr>>12) ^ lfsr>>10)&0x1;
	   lfsr =  (lfsr << 1)|bit;
	   if((lfsr>>6) & 0x01)
	   {
		P1OUT^=0x41;
		while(!(TACTL&0x01));
		TACTL=TACTL & ~0x1;
		while(!(TACTL&0x01));
		TACTL=TACTL & ~0x1;
	   }
	   P1OUT^=0x41;
	}while(lfsr!=0xace1);
}

