#include<avr/io.h>
#include<util/delay.h>
void main(void)
{
DDRD=0xFF;
DDRA=0xFF;
PORTD=0x00;
PORTA=0x00;
while(1)
{
PORTD=(1<<4)|(1<<5);
PORTA=(1<<0)|(1<<1)|(1<<2)|(1<<3);
_delay_ms(2000);
PORTD=(0<<4)|(1<<5);
PORTA=(1<<0)|(1<<1)|(1<<2)|(1<<3);
_delay_ms(2000);
PORTD=(1<<4)|(0<<5);
PORTA=(1<<0)|(1<<1)|(1<<2)|(1<<3);
_delay_ms(2000);
PORTD=(1<<4)|(1<<5);
PORTA=(0<<0)|(1<<1)|(1<<2)|(1<<3);
_delay_ms(2000);
PORTD=(1<<4)|(1<<5);
PORTA=(1<<0)|(0<<1)|(1<<2)|(1<<3);
_delay_ms(2000);
PORTD=(1<<4)|(1<<5);
PORTA=(1<<0)|(1<<1)|(0<<2)|(1<<3);
_delay_ms(2000);
PORTD=(1<<4)|(1<<5);
PORTA=(1<<0)|(1<<1)|(1<<2)|(0<<3);
_delay_ms(2000);
}
}