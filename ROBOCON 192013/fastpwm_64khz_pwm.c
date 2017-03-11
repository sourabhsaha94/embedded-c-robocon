#include<avr/io.h>
#include<util/delay.h>

void main()
{
	DDRD = 0XFF;
	DDRC = 0XFF;
	PORTC = 0x00;
	TCCR2 = 0X61;	//0b01100100
	unsigned char a,flag;
	a=1;
	flag = 0;

	while(1)
	{
	
	_delay_ms(50);
	if(flag == 0)
		{
		
		a++;
		OCR2 = a;
		if(a==254)
			flag=1;
		
		
		}
	if(flag == 1)
		{
		
		
		a--;
		OCR2= a;
		if(a==1)
			{
				flag=0;
				PORTC ^= 0x04;
			}
		
		}

	}
}