#include<avr/io.h>
void main(void)
{
DDRB=0xFF;
DDRB &= ~(1<<PB1);
while(1)
{
	PORTB=(1<<PINB0);
	if(PINB & (1<<PB1))
	{
		PORTB |=(1<<PB2);
	}
	else
	{
	PORTB &= ~(1<<PB2);
	}
}
}


