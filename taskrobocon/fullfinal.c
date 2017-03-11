#include<avr/io.h>
#include<util/delay.h>
void main(void)
{
  DDRA=0b11111111;
  DDRB=0b11101101;
  DDRD=0b11110101;
  PORTA=0b00001100;
  PORTB=0b00010010;
  PORTD=0b00011010;
 	while((PIND&0b00001000)!=0)	//till back switch not hit
		{
			if((PINB&0x12)==0)
			{
			PORTA=0b00001100;//reverse motion
			}
			else if((PINB&0x02)!=0)//turn left
			{
			PORTA=0b01001100;
			}
			else//turn right
			{
			PORTA=0b00011100;
			}
		}
		PORTD=0b00011010;
		PORTA=0b01010100;//claw activates
		_delay_ms(500);
		PORTA=0b01010000; //up mechanism active
		_delay_ms(500);
		PORTA=0b01010100; //up mechanism deactivated
		_delay_ms(100);
		PORTD&=0b11101111; //swivel motion started
		_delay_ms(1000);
		PORTD|=0b00010000; //swivel motion end
		PORTA=0b01011100;//claw stops
		_delay_ms(500);
		PORTD=0b00011010;
			while((PIND&0b00000010)!=0)
			{ //till front switch not hit
			if((PINB&0x12)==0) 
			{
			 PORTA=0b11111100; //forward motion
			}
			else if((PINB&0x10)!=0)//turn left
			{
			PORTA=0b10111100;
			}
			else//turn right
			{
			PORTA=0b11101100;
			}
			}
			PORTD=0b00011010;
			PORTA=0b01010100;//claw activated
			_delay_ms(500);
			PORTD&=0b11101111; //swivel motion started
		     _delay_ms(1000);
		    PORTD|=0b00010000; //swivel motion end
			PORTA=0b01011100; //claw deactivated
			_delay_ms(500);
			PORTD=0b00011010;
			while((PIND&0b00001000)!=0)	//till back switch not hit
			{
			if((PINB&0x12)==0)
			{
			PORTA=0b00001100;//reverse motion
			}
			else if((PINB&0x02)!=0)//turn left
			{
			PORTA=0b01001100;
			}
			else//turn right
			{
			PORTA=0b00011100;
			}
			}
			
			PORTA=0b01011100;
		
			
			
	}	
