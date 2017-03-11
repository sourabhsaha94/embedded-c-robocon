#include<avr/io.h>
#include<util/delay.h>
#include<math.h>

/*#define clk 0
#define cmd	2
#define data 1
#define att 4
*/

int i;
unsigned char a;
unsigned char data;

void read()
{
	
	PORTC |= 0x01;		//clock high
	PORTC |= 0x10;		//att high
	
	//BYTE1
	_delay_us(5);
	PORTC &= 0xEF;		//att low
	
	PORTC |= 0x04;		//cmd high
	
	PORTC &= 0xFE;		//clock low
	_delay_us(5);
	PORTC |= 0x01;		//clock high
	_delay_us(5);
	
	PORTC &= 0xFB;		//cmd low
	
	for(i = 0;i<7;i++)
	{
		PORTC &= 0xFE;		//clock low
		_delay_us(5);
		PORTC |= 0x01;		//clock high
		_delay_us(5);
	}
	
	
	//BYTE 2
	
	PORTC &= 0xFB;		//cmd low
	
	PORTC &= 0xFE;		//clock low
	_delay_us(5);
	PORTC |= 0x01;		//clock high
	_delay_us(5);
	
	PORTC |= 0x04;		//cmd high
	
	PORTC &= 0xFE;		//clock low
	_delay_us(5);
	PORTC |= 0x01;		//clock high
	_delay_us(5);
	
	PORTC &= 0xFB;		//cmd low
	
	for(i = 0;i<4;i++)
	{
		PORTC &= 0xFE;		//clock low
		_delay_us(5);
		PORTC |= 0x01;		//clock high
		_delay_us(5);
	}
	
	PORTC |= 0x04;		//cmd high
	
	PORTC &= 0xFE;		//clock low
	_delay_us(5);
	PORTC |= 0x01;		//clock high
	_delay_us(5);
	
	PORTC &= 0xFB;		//cmd low
	
	PORTC &= 0xFE;		//clock low
	_delay_us(5);
	PORTC |= 0x01;		//clock high
	_delay_us(5);
	
	
	//BYTE3
	
	PORTC &= 0xFB;		//cmd low
	
	for(i = 0;i<8;i++)
	{
		PORTC &= 0xFE;		//clock low
		_delay_us(5);
		PORTC |= 0x01;		//clock high
		_delay_us(5);
	}
	
	//	PORTC &= 0xEF;		//att high
	
	//BYTE4
	for(i = 7;i<=0;i--)
	{
		
		PORTC &= 0xFE;		//clock low
		_delay_us(5);
		if((PINB&(0x02))==0x00)
			a=0;
		else
			a=1;
		data = data + pow(a,i);
		
		PORTC |= 0x01;		//clock high
		_delay_us(5);
	}
	//PORTA = data;
	
	
	//BYTE5
	for(i = 7;i<=0;i--)
	{
		
		PORTC &= 0xFE;		//clock low
		_delay_us(5);
		if((PINB&(0x02))==0x00)
			a=0;
		else
			a=1;
		data = data + pow(a,i);
		
		PORTC |= 0x01;		//clock high
		_delay_us(5);
	}
	//PORTA = data;
	
	PORTC |= 0x10;		//att high
}

void main()
{	
	DDRC = 0xFD;
	DDRD = 0xFF;
	DDRA = 0xFF;
	PORTC = 0xFF;
	while(1)
	{
	read();
	}
}