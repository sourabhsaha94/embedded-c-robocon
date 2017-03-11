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
int pre=0,next=0,pre1=0,next1=0;
PORTA=0x05;
	OCR1A=0;
	OCR1B=0;
	_delay_ms(5000);
	OCR1A=50;
	OCR1B=45;
	_delay_ms(5000);
	OCR1A=60;
	OCR1B=45;
	_delay_ms(5000);
	OCR1A=65;
	OCR1B=45;
	_delay_ms(5000);
	OCR1A=70;
	OCR1B=48;
	_delay_ms(5000);
	OCR1A=0;
	OCR1B=0;
	_delay_ms(5000);
	
}