#include<avr/io.h>
#include<util/delay.h>
void main()
{
DDRB=(1<<PB5)|(1<<PB7)|(1<<PB4);
SPCR=(1<<SPE)|(1<<MSTR)|(1<<SPR0);

DDRA=0XFF;
PORTA=0XAA;
DDRD=0X00;
_delay_ms(10);
PORTD = 0xFF;





while(1)
	{
	if(PIND<255)
		PORTA = 0xFF;
	else
		PORTA = 0x00;
	SPDR = PINA;
	while(!(SPSR & (1<<SPIF)))
	;

	}

}