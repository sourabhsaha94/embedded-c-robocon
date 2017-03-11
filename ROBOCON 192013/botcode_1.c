// PORTA ,PORTD output for  various motordrivers
// PORTB for sensor inputs
// PORTC for hitswitch's input
/*
PORTA ->
pin7
pin6
pin5-clamp driver
pin4-clamp driver *
pin3-motor 2 driver
pin2-motor 2 driver *
pin1-motor 1 driver
pin0-motor 1 driver *
*/

/*
PORTB ->
pin7
pin6
pin5
pin4
pin3
pin2-sensor input s3
pin1-sensor input s2
pin0-sensor input s1
*/

/*
PORTC ->
pin7
pin6
pin5
pin4
pin3
pin2
pin1-back buffer input s2
pin0-front buffer input s1
*/

/*
PORTD ->
pin7-pulley motor
pin6
pin5-speed motor 2
pin4-speed motor 1
pin3
pin2
pin1
pin0
*/



#include<avr/io.h>
#include<util/delay.h>

void main()
{
	DDRA = 0xFF;
	DDRB = 0x00;
	DDRC = 0x00;
	DDRD = 0xFF;
	PORTA = 0x00;
	PORTD = 0x00;
	int direction = 0;
	int clamped = 0;
	int reverse = 0;
	int endtask = 0;
	unsigned char s1,s2,s3,b1,b2;
	while(1)
	{	
		s1 = PINB&0x01;
		s2 = PINB&0x02;
		s3 = PINB&0x01;
		b1 = PINC&0x01;
		b2 = PINC&0x02;
		
		if(direction == 0)
		{
			//code for forward direction
			PORTA &= 0xFA;
			PORTA |= 0x0A;
			while(s2 == 0x02)
			{
				PORTD |= 0x30;
				s1 = PINB&0x01;
				s2 = PINB&0x02;
				s3 = PINB&0x01;
				b1 = PINC&0x01;
				
			}
			
			while(s1 == 0x01)
			{
			
				PORTD &= 0xEF;
				PORTD |= 0x20;
				s1 = PINB&0x01;
				s2 = PINB&0x02;
				s3 = PINB&0x01;
				b1 = PINC&0x01;
			}
			
			while(s3 == 0x04)
			{
				PORTD &= 0xDF;
				PORTD |= 0x10;
				s1 = PINB&0x01;
				s2 = PINB&0x02;
				s3 = PINB&0x01;
				b1 = PINC&0x01;
			}
			
			if(b1==0x01)
			{
				direction = 1;
				PORTA = 0x00;
			}
		}
		
		if(direction == 1)
		{
			if(clamped == 0)
			{
				//insert code for clamping
				clamped = 1;
			}
			
			if((clamped==1)&&(reverse==0))
			{
				//turn the pulley around
				reverse = 1;
			}
			
			if(reverse == 1)
			{
				//code for reverse direction
				
				PORTA &= 0xF5;
				PORTA |= 0x05;
				while(s2 == 0x02)
				{
					PORTD |= 0x30;
					s1 = PINB&0x01;
					s2 = PINB&0x02;
					s3 = PINB&0x01;
					b2 = PINC&0x02;
					
				}
				
				while(s1 == 0x01)
				{
				
					PORTD &= 0xEF;
					PORTD |= 0x20;
					s1 = PINB&0x01;
					s2 = PINB&0x02;
					s3 = PINB&0x01;
					b2 = PINC&0x02;
				}
				
				while(s3 == 0x04)
				{
					PORTD &= 0xDF;
					PORTD |= 0x10;
					s1 = PINB&0x01;
					s2 = PINB&0x02;
					s3 = PINB&0x01;
					b2 = PINC&0x02;
				}
				
				if(b2==0x02)
				{
					direction = 2;
					PORTA = 0x00;
					endtask = 1;
				}
			}
			
			if(endtask == 1)
			{
				//insert code for unclamping
			}
		}
	}
}