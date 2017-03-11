#include<avr/interrupt.h>
#include<avr/io.h>
#include<util/delay.h>
#define B PINB0
long int volatile count=0;
ISR(INT0_vect)
{
	if(!B)
	{
	count--;//backward
	}	
	else
	{
	count++;//forward
	}
}
void main(void)
{
DDRB=0xFF;//output led
DDRD=0x00;//int0 PD2 output
PORTD=(1<<PD2);//pin held high
SREG|=0x80;//enable interrupt
MCUCR=(1<<ISC01)|(1<<ISC00);//rising edge triggers interrupt
GICR=(1<<INT0);//interrupt INT0
	while(1)
	{
	//display count on lcd
	}
}