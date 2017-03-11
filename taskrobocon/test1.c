#include<avr/io.h>
void main(void)
{
DDRB=0b00000101;
PORTB=0b00000000;
while(1)
{
PORTB=(1<<PINB0);
if(PINB & (1<<PB1))
{
PORTB=(1<<PINB2);
}
else
{
PORTB=(0<<PINB2);
}
}
}