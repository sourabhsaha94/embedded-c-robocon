#include<avr/io.h>
#include<util/delay.h>
#define I PINC//in5
#define J PINB//in8x
void main(void)
{
int ps2data;
int j=30;
DDRD=0xFF;
DDRA=0xFF;
DDRB=0xFF;
DDRC=0xFF;
UBRRL=207;//set baud rate 4800 with U2X reset
UCSRB=(1<<RXEN);//reciever enabled
UCSRC=(0<<UMSEL)|(1<<URSEL)|(0<<USBS)|(3<<UCSZ0);//8bit frame size 1 stop bits
TCCR1A=0xA1;
TCCR1B=0x01;
PORTA=0x00;
OCR1A=0;
 OCR1B=0;
 int gear = 1;
 int x;
	while(1)
	{
		while(!(UCSRA&(1<<RXC)))//till reciev complete
		;
		PORTC=UDR;
		if(PINC==0x01)
		{ 
			while(!(UCSRA&(1<<RXC)))//till reciev complete
			;
			PORTC=UDR;
			_delay_us(1);
			while(!(UCSRA&(1<<RXC)))//till reciev complete
			;
			PORTB=UDR;
			_delay_us(1);
			while(!(UCSRA&(1<<RXC)))//till reciev complete
			;
			ps2data=UDR;
			_delay_us(1);
			OCR1A=5;
			OCR1B=5;
			x=ps2data;
			if(ps2data<127)//forward motion
			{
				PORTA=0x05;
				OCR1A=((127-x)*2)/gear;
				OCR1B=((127-x)*2)/gear;
				
			}
			if(ps2data<127&&J==0x00)
			{
			PORTA=0x05;
			OCR1A=((127-x)*2)/gear;
			OCR1B=(127-x)/gear;
			}
			else if(ps2data<128&&J==0xFF)
			{
			PORTA=0x05;
			OCR1A=(127-x)/gear;
			OCR1B=((127-x)*2)/gear;
			}
			else if(ps2data>=128&&J==0xFF)
			{
			PORTA=0x00;
			OCR1A=(x-128)/gear;
			OCR1B=((x-128)*2)/gear;
			}
			else if(ps2data>=128&&J==0x00)
			{
			PORTA=0x00;
			OCR1A=((x-128)*2)/gear;
			OCR1B=(x-128)/gear;
			}
			else if((ps2data>=128))//back motion
			{
				PORTA=0x00;
				OCR1A=((x-128)*2)/gear;
				OCR1B=((x-128)*2)/gear;
				
			}
			//////////////////////////gear system/////////////////////////////
			if(((I&0x01)==0x00)&&gear==1)//r2 high gear 1
			{
			gear++;
			if(gear==3)
			gear=2;
			}
			if(((I&0x01)==0x00)&&gear==2)//r2 high gear 2
			{
			gear++;
			if(gear==4)
			gear=3;
			}
			if(((I&0x01)==0x00)&&gear==3)//r2 high gear 3
			{
			gear++;
			if(gear==5)
			gear=4;
			}
			if((I&0x02)==0x00&&gear==2)//l2 low gear1
			{
			gear--;
			if(gear==0)
			gear=1;
			}
			if((I&0x02)==0x00&&gear==3)//l2 low gear2
			{
			gear--;
			if(gear==1)
			gear=2;
			}
			if((I&0x02)==0x00&&gear==4)//l2 low gear3
			{
			gear--;
			if(gear==2)
			gear=3;
			}
		}
	}
}
