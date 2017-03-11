

#include<avr/io.h>
#include<util/delay.h>


void main()
{
DDRA = 0x00;
DDRB = 0XFF;
int flag = 0;
int task1 = 0;
int task2 = 0;
int task3 = 0;
int task4 = 0;
int done = 0;

unsigned char s0,s1,s2,s3,s4,s5,b0,b1;
while(1)
{
	s0 = PINA & 0x01;
	s1 = PINA & 0x02;
	s2 = PINA & 0x04;
	s3 = PINA & 0x08;
	s4 = PINA & 0x10;
	s5 = PINA & 0x20;
	b0 = PINC & 0x01;
	b1 = PINC & 0x02;
	b2 = PINC & 0x04;


	if(b0==0x01)
	{
	flag=1;
	}

	if(flag==0)									// Going Forward
	{
		if((s3==0x08)&&(s2==0x04))			// 00xx00
		{
			PORTB = 0x36;						// Both Wheels forward
			_delaf_ms(100);
		}
		
		if((s4==10)&&(s3==0x08))			// 0xx000
		{
			if(!((s3==0x08)&&(s2==0x04)))	// till 00xx00
			{
				PORTB = 0x32;					// Turn left
				_delaf_ms(100);
			}
		}
		
		if((s5==20)&&(s4==0x10))			// xx0000
		{
			if(!((s3==0x08)&&(s2==0x04)))	// till 00xx00
			{
				PORTB = 0x10;					// Turn Sharply left
				_delaf_ms(100);
			}
		}
		
		if((s2==04)&&(s1==0x02))			// 000xx0
		{
			if(!((s3==0x08)&&(s2==0x04)))	// till 00xx00	
			{
				PORTB = 0x16;					// Turn right
				_delaf_ms(100);
			}
		}
		
		if((s0==01)&&(s1==0x02))			// 0000xx
		{
			if(!((s3==0x08)&&(s2==0x04)))	// till 00xx00
			{
				PORTB = 0x02;					// Turn Sharply right
				_delaf_ms(100);
			}
			
		}										// End of Forward Code
		if(flag == 1)
				PORTB = ox3F;							// Stop Forward motion
				_delaf_ms(100);

	}
	if(flag == 1)
	{	
		if(task1 == 0)
		{
			PORTD &= 0xFD;
			PORTD |= 0x01;						//PORTD = xxxxxx01
			_delay_ms(2000);
			task1 = 1;							//leaf has been picked up
			PORTD |= 0x02; 						//PORTD = xxxxxx11
			_delaf_ms(100);
		}
		
		if((task1 == 1)&&(task2 == 0))
		{
			PORTD &= 0xFB;
			PORTD |= 0x08;						//PORTD = xxxx01xx
			_delay_ms(5000);
			if(b0 == 0x00)
				task2 = 1;							//pulley is rotated
		}
		if((task2 == 1)	&&(task3==0))						//Start reverse motion
		{

			if(b1==0x01)
			{
				task3=1;
				
			}
			if((s3==0x08)&&(s2==0x04))			// 00xx00
			{
				PORTB = 0x36;						// Both Wheels forward
				_delaf_ms(100);
			}
		
			if((s4==10)&&(s3==0x08))			// 0xx000
			{
				if(!((s3==0x08)&&(s2==0x04)))	// till 00xx00
				{
					PORTB = 0x29;					// Turn right
					_delaf_ms(100);
				}
			}
		
			if((s5==20)&&(s4==0x10))			// xx0000
			{
				if(!((s3==0x08)&&(s2==0x04)))	// till 00xx00
				{
					PORTB = 0x08;					// Turn Sharply right
					_delaf_ms(100);
				}
			}
		
			if((s2==04)&&(s1==0x02))			// 000xx0
			{
				if(!((s3==0x08)&&(s2==0x04)))	// till 00xx00	
				{
					PORTB = 0x0D;					// Turn left\
					_delaf_ms(100);
				}
			}
		
			if((s0==01)&&(s1==0x02))			// 0000xx
			{
				if(!((s3==0x08)&&(s2==0x04)))	// till 00xx00
				{
					PORTB = 0x01;					// Turn Sharply right
					_delaf_ms(100);
				}
			}	
		}
		if(task3==1)
		{
			PORTB = 0x3F							//stop reverse motion
			task4 = 1;
			_delaf_ms(100);
		}
		if((task4 == 1)&&(done == 0))
		{
			PORTD &= 0xFE;
			PORTD |= 0x02;
			done = 1;							//leaf has been dropped
			PORTD |= 0x02; 						//PORTD = xxxxxx11
			_delaf_ms(100);
		}
		
	}

}
}