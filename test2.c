#include<avr/io.h>
#include<util/delay.h>
void main(void)
{
DDRB=0xFF;
PORTB=0b11111111;

DDRA=0xFF;
PORTA=0b11111111;

DDRC=0xFF;
PORTC=0b11111111;

DDRD=0xFF;
PORTD=0b11111111;

while(1)
{
PORTB=0x00;
_delay_ms(1000);
PORTB=0xFF;
_delay_ms(1000);

PORTA=0x00;
_delay_ms(1000);
PORTA=0xFF;
_delay_ms(1000);

PORTC=0x00;
_delay_ms(1000);
PORTC=0xFF;
_delay_ms(1000);

PORTD=0x00;
_delay_ms(1000);
PORTD=0xFF;
_delay_ms(1000);



}
}