#include<avr/io.h>
#include<util/delay.h>
#include"avrlibdefs.h"
#include<mit_tech/serial_lcd.h>
void main()
{	
	DDRF = 0x00;
	DDRC = 0xFF;
	
	int data;
	while(1)
	{
		ADMUX = 0xE3;
		ADCSRA = 0xD7;
		ADCSRB = 0x00;
		while(!(ADCSRA&(1<<ADSC)))
		;
		data = ADCH;
		_delay_ms(100);
		PORTC = data;
	}
	
	
}