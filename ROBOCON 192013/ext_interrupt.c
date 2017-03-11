#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>
int main()
{
DDRA = 0xFF;
PORTA = 0xFF;
PORTD = 0xFF;
sei();
MCUCR = 0x00;
GICR = 0xD0;
TCCR0 = 0x45;
TIMSK = 0x01;
while(1)
	{
	
	_delay_ms(100);
	}
}

ISR(SIG_INTERRUPT0)
{
PORTA = 0xAA;
_delay_ms(10);

}

ISR(SIG_INTERRUPT1)
{
PORTA = 0x55;
_delay_ms(10);
}

ISR(TIMER0_OVF_vect)
{
PORTA = 0x80;
_delay_ms(10);
}

