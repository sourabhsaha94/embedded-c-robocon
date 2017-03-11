#include<avr/interrupt.h>
#include<avr/io.h>
#include<util/delay.h>
int volatile flag=0;
ISR(TIMER0_COMP_vect)
{
flag^=1;
}
void main(void)
{
SREG|=0x80;
DDRA=0xFF;
TCCR0=0x1D;
TIMSK|=0x02;
while(1)
{
OCR0=100;
if(flag==1)
{
PORTA=0x00;
}
else
{
PORTA=0xFF;
}
}
}