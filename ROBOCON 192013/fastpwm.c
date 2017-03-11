#include<avr/io.h>
#include<util/delay.h>

void main()
{
	DDRB = 0XFF;
	TCCR0 = 0X71;	//0b01100100
	OCR0 = 100;
	while(1)
	{
	}
	
}