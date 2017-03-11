#include<avr/io.h>
void main(void)
{
DDRB=0xDF;
while(1)
{
PORTB=0x40;
if((PINB&0x20)!=0)
{
PORTB|=0x01;
}
else
{
PORTB&=0xFE;
}
}
}