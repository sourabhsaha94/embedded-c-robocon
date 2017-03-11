#include<avr/io.h>
#include<util/delay.h>
#define I PINC
#define J PINB
int main()
{
	DDRA = 0xFF;
	DDRB = 0xFF;
	DDRC = 0xFF;
	UCSRB = 0x10;
	UCSRC = 0x86;
	UBRRL = 207;
	TCCR1A = 0xA1;
	TCCR1B = 0x01;
	unsigned char byte5;
int gear = 1;
int pre=0,next=0,pre1=0,next1=0;
	while(1)
	{
	OCR1A=0;
	OCR1B=0;
	while(!(UCSRA & (1<<RXC)))
		;
		PORTC = UDR;
		if(PINC==0x01)
		{
		while(!(UCSRA & (1<<RXC)))
		;
		PORTC = UDR;//recieving 7byte I
		_delay_us(1);
		while(!(UCSRA & (1<<RXC)))
		;
		PORTB = UDR;//recieving 9 byte J
		_delay_us(1);
		while(!(UCSRA & (1<<RXC)))
		;
		byte5 = UDR;//recieving 5 byte
		_delay_us(1);
			if(I==0x00)//forward
			{
			PORTA=0x05;
				if(J==0x00)
				{
				OCR1A=0;
				OCR1B=128/gear;
				}
				else if(J==0xFF)
				{
				OCR1A=128/gear;
				OCR1B=0;
				}
				else
				{
				OCR1A=128/gear;
				OCR1B=128/gear;
				}
			}
			if(I==0xFF)//backward
			{
			PORTA=0x00;
				if(J==0x00)
				{
				OCR1A=128/gear;
				OCR1B=0;
				}
				else if(J==0xFF)
				{
				OCR1A=0;
				OCR1B=128/gear;
				}
				else
				{
				OCR1A=128/gear;
				OCR1B=128/gear;
				}
				
			}
		if((byte5&0x01)==0x00)//r2 high gear
		next = 1;
		else
		next = 0;
		if((next==0)&&(pre==1))
		{
		gear++;
		if(gear==6)
		gear=5;
		}
		pre=next;
	
		if((byte5&0x02)==0x00)//l2 low gear
		next1 = 1;
		else
		next1 = 0;
	
		if((next1==0)&&(pre1==1))
		{
		gear--;
		if(gear==0)
		gear=1;
		}
		pre1=next1;
		
	}
}
}
/*
	if((ps2data4&0x80)==0x80)
		PORTC |= 0x0A;
		
	else
		PORTC &= 0xF5;
		
		
	
	
	if((right-127)>=0)
	{
		PORTC &= 0xFB;
		right=right-127;
	}
	else
	{
		PORTC |= 0x04;
		right = 127-right;
	}
	
	if((left-127)>=0)
	{
		PORTC &= 0xFE;
		left=left-127;
	}
	else
	{
		PORTC |= 0x01;
		left = 127-left;
	}
	
	
	OCR1A=right/gear;
	OCR2A=left/gear;
	*/