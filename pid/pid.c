#include<avr/io.h>
#include<util/delay.h>
int  main(void)
{
unsigned int val;
int x;
float P=0,I=0,D=0,kp=20,kd=1,ki=0.8,prev=0,error=0,speed=100,top=154;
DDRL=0X00; //sensor input
PORTL=0X00; //sensor initialization
DDRB=0XFF; //H4 H3 PWM initialization
DDRC=0XFF; //Direction break for both motors
TCCR2A=0x81;//Timer 4 initialization
TCCR2B=0x01;
TCCR1A=0x81;
TCCR1B=0x01;
PORTC=0X05;//direction break

while(1)
{
	val=PINL;
	switch(val)
	{
	case 255:x=-6;
	break;
	case 127:x=-4;//01111111
	break;
	case 254:x=4;//11111110
	break;
	case 63:x=-2;//00111111
	break;
	case 126:x=-0;//01111110
	break;
	case 252:x=2;//11111100
	break;
	case 31:x=-1;//00011111
	break;
	case 62:x=-1;//00111110
	break;
	case 124:x=0;//01111100
	break;
	case 248:x=1;//11111000
	break;
	case 15:x=-2;//00001111
	break;
	case 30:x=-1;//00011110
	break;
	case 60:x=0;//00111100
	break;
	case 120:x=1;//01111000
	break;
	case 240:x=2;//11110000
	break;
	case 1:x=-4;//00000001
	break;
	case 3:x=-3;//00000011
	break;
	case 7:x=-2;//00000111
	break;
	case 6:x=-2;//00000110
	break;
	case 14:x=-1;//00001110
	break;
	case 12:x=-1;//00001100
	break;
	case 8:x=0;//00001000
	break;
	case 24:x=1;//00011000
	break;
	case 56:x=1;//00111000
	break;
	case 48:x=2;//00110000
	break;
	case 112:x=2;//01110000
	break;
	case 96:x=3;//01100000
	break;
	case 224:x=3;//11100000
	break;
	case 192:x=4;//11000000
	break;
	case 128:x=5;//10000000
	break;
	
	}
	P=x*kp;
	I=I+x;
	I=I*ki;
	D=kd*(x-prev);
	error=P+I+D;
	if(error>top)
	{
	error=top-1;
	OCR1A=speed+error;
	OCR2A=speed-error;
	}
	else
	{
	OCR1A=speed+error;
	OCR2A=speed-error;
	}
	prev=x;
}
}