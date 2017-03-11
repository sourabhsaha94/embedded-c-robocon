#include<avr/io.h>
#include<util/delay.h>
void main()
{
DDRB=(1<<PB6);
SPCR=(1<<SPE);


DDRA = 0xFF;
while(1)
{
	while(!(SPSR & (1<<SPIF)))
	;
	PORTA = SPDR;
	
	
}

}