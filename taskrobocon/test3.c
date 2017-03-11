#include<avr/io.h>
void main(void)
{
DDRB=0xFF;
while(1)
{
PORTB =0x01;
if(PINB0==0)
{
PORTB=(1<<PB7);
}
else
PORTB=(0<<PB7);
}
}