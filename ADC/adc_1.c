#include<avr/io.h>
#include"delay.h"
void main(void)
{
DDRA=0xFF;
DDRF=0x00;
PORTF = 0x00;
DDRB=0xFF;
PORTB=0xAA;
ADCSRB=0x00;
ADCSRA=0x86;//(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(0<<ADPS0);//ADC enabled prescaled to 128
ADMUX=0xE3;//reference voltage 2.56 ADLAR set ADC3 selected
	while(1)
	{
		
		
		ADCSRA |= 0x40;//conversion started
		
		ADCL=0;
		ADCH=0;
		
		while((ADCSRA&(0x40)));//till conversion not complete
		
		PORTA=ADCH;//ADC reg read
		//PORTB=ADCH;
		
	}
}