#include<avr/io.h>
void main(void)
{
DDRB=0b11101101;
DDRD=0b11101101;
DDRA=0xFF;
DDRC=0b11011011;
unsigned char i,j;
while(1)
{
  PORTD=0b00010010;
  PORTA=0x00;
   PORTC=0b00010010;
   while(PIND!=0b00010000)//hitswitch infront not pressed forward
  {
	PORTB =0b00010010;
	i=PINB;
	if((i&0x12)==0)
	{
	//make bot go straight
	PORTA=0xF0;//right motor high
	//left motor high
	}
	else if((i&0x02)!=0)
	{
	//make bot turn left
	PORTA=0xE0;
  }
  else
	{
	//make bot turn right
	PORTA=0xB0;
  }
  }
  if(PIND==0b00010000)
  {
  j=PIND;
  while((j&0x10)!=0)//hitswitch back not  pressed backward
  {
  PORTB =0b00010010;
  i=PINB;
	if((i&0x12)==0)
	{
	//make bot go reverse
	PORTA=0x00;
	}
	else if((i&0x10)!=0)
	{
	//make bot turn left
	PORTA=0xE0;
	}
	else
	{
	//make bot turn right
	PORTA=0xB0;
  }
  }
  }
}
}


