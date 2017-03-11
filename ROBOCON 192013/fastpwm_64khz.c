#include<avr/io.h>
#include<util/delay.h>

void main()
{
	DDRB = 0XFF;
	TCCR0 = 0X69;	//0b01100100
	OCR0 = 128;
	while(1)
	{
	_delay_ms(2000);
	OCR0 = 64;
	_delay_ms(2000);
	OCR0 = 192;
	}
}