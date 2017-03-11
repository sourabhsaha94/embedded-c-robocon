#include<avr/io.h>
#include<util/delay.h>
void main()
{
	DDRA = 0x00;
	DDRB = 0xFF;	
	PORTB = 0x00;
	PORTA = 0xFF;
	unsigned char a;
	int flag =0;
	while(1)
	{	
		a = PINA&0x01;
		while(a==1)
		{
			PORTB = 0xF0;
			a = PINA&0x01;
			flag = 1;
		}
		while(flag==1)
		{
			PORTB = 0x0F;
			a = PINA&0x01;
		}
	}
}