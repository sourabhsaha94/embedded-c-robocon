#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
void main()
{
sei();
DDRB=(1<<PB6);
SPCR=(1<<SPE);


DDRA = 0xFF;
while(1)
{
	//while(!(SPSR & (1<<SPIF)))
	//;
	//PORTA = SPDR;		//	w/o interrupt
	
	
}

}
ISR(SPI_STC_vect)
{
PORTA = SPDR;
}