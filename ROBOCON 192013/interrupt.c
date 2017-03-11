#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>
int main()
{
DDRA = 0xFF;
PORTA = 0xFF;
SREG = 0x80;
sei();
TCCR0 = 0x45;
while(1)
	{
	_delay_ms(1000);
	TIMSK = 0x01;
	
	}
}

ISR(TIMER0_OVF_vect)
{
PORTA = 0xAA;
_delay_ms(400);
}