#include<avr/io.h>
#include<util/delay.h>
int main()
{	
	DDRC = 0x00;
	PORTC = 0xFF;
	DDRA = 0xFF;
	UCSRB = 0x08;
	UCSRC = 0x86;
	UBRRL = 207;
	while(1)
	{
	
	while(!(UCSRA & (1<<UDRE)))
	;
	UDR = PINA;
	_delay_ms(1);
	
	PORTA = 0x00;
	
	while(!(UCSRA & (1<<UDRE)))
	;
	UDR = PINA;
	_delay_ms(1);
	}
}