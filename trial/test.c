#include<avr/io.h>
void main(void)
{
DDRL=0x00;
PORTL=0x00;
int i;
while(1)
{
DDRL=0x00;
PORTL=0x00;
i=PINL;
if(i==3)
{
	if(i==7)
	{
	DDRL=0b00000100;
	PORTL=0b00000000;
	}
}
if(i==6)
{
	if(i==14)
	{
	DDRL=0b00001000;
	PORTL=0b00000000;
	}
}
if(i==12)
{
	if(i==28)
	{
	DDRL=0b00010000;
	PORTL=0b00000000;
	}
}
if(i==24)
{
	if(i==56)
	{
	DDRL=0b00100000;
	PORTL=0b00000000;
	}
}
if(i==48)
{
	if(i==112)
	{
	DDRL=0b01000000;
	PORTL=0b00000000;
	}
}
if(i==96)
{
	if(i==224)
	{
	DDRL=0b10000000;
	PORTL=0b00000000;
	}
}
}
}