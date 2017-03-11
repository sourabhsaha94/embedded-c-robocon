#include<avr/interrupt.h>
#include<avr/io.h>
#include<util/delay.h>
int volatile flag=0;
ISR(INT0_vect)
{
flag^=1;
}
void main(void)
{
DDRA=0xFF;//output led
DDRD=0x00;//int0 PD2 output
PORTD=(1<<PD2);//pin held high
SREG|=0x80;//enable interrupt
MCUCR=(0<<ISC01)|(1<<ISC00);//logical change triggers interrupt
GICR=(1<<INT0);//interrupt INT0
while(1)
{
if(flag==1)
{
PORTA=0xAA;
}
else
{
PORTA=0xFF;
}
}
}