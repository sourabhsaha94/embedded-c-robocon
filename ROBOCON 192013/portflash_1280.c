#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>
int main()
{

DDRA = 0xFF;
PORTA = 0xAA;

DDRB = 0xFF;
PORTB = 0xAA;

DDRC = 0xFF;
PORTC = 0xAA;

DDRD = 0xFF;
PORTD = 0xAA;

DDRE = 0xFF;
PORTE = 0xAA;

DDRF = 0xFF;
PORTF = 0xAA;

DDRG = 0xFF;
PORTG = 0xAA;



DDRJ = 0xFF;
PORTJ = 0xAA;

DDRK = 0xFF;
PORTK = 0xAA;

DDRL = 0xFF;
PORTL = 0xAA;


while(1)
	{
	
	PORTA ^= 0xFF;
	_delay_ms(100);
	
	PORTB ^= 0xFF;
	_delay_ms(100);
	
	PORTC ^= 0xFF;
	_delay_ms(100);
	
	PORTD ^= 0xFF;
	_delay_ms(100);
	
	PORTE ^= 0xFF;
	_delay_ms(100);
	
	PORTF ^= 0xFF;
	_delay_ms(100);
	
	PORTG ^= 0xFF;
	_delay_ms(100);
	
	
	
	PORTJ ^= 0xFF;
	_delay_ms(100);
	
	PORTK ^= 0xFF;
	_delay_ms(100);
	
	PORTL ^= 0xFF;
	_delay_ms(100);
	}
}

