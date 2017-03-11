#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>
int main()
{
DDRA = 0xFF;
PORTA = 0xFF;
SREG = 0x80;
sei();
TCCR0=0x0D;

OCR0 = 0X26;
TIMSK = 0x02;
while(1)
	{
	
	
	}
}

ISR(TIMER0_COMP_vect)
{
PORTA ^= 0xFF;
}