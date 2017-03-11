#include<avr/io.h>
#include<util/delay.h>
void main()
{
DDRL = 0x00;			//sensor input
DDRB = 0xFF;			//motor output
TCCR1A = 0x81;
TCCR1B = 0x01;
TCCR1C = 0x00;
TCCR2A = 0x81;
TCCR2B = 0x01;
DDRC = 0xFF;			//motor output


unsigned char input;
int prop,diff,inte,lprop;
int kp = 2;
int ki = 0;
int kd = 0;
int calc_err;
int x;

while(1)
	{	
		_delay_ms(10);
		input = PINL&0x7F;
		switch(input)
		{
		case 1:
			x=3;
			break;
		case 2:
			x=2;
			break;
		case 3:
			x=2;
			break;
		case 4:
			x=1;
			break;
		case 6:
			x=1;
			break;
		case 8:
			x=0;
			break;
		case 12:
			x=0;
			break;
		case 16:
			x=-1;
			break;
		case 24:
			x=-1;
			break;
		case 32:
			x=-2;
			break;
		case 48:
			x=-2;
			break;
		case 64:
			x=-3;
			break;
		case 96:
			x=-3;
			break;
		
		}
		
		diff = x;
		prop = diff;
		inte = inte + prop;
		diff = prop - lprop;
		lprop = prop;
		calc_err = (kp*prop)+(ki*inte)+(kd*diff);
		PORTC = 0x05;
		if(calc_err>10)
			calc_err=10;
		if(calc_err<-10)
			calc_err=-10;
		
		if(calc_err>0)
		{
				calc_err = -calc_err;
				OCR1AL = calc_err;
				OCR1AH = 0;
				OCR2A = calc_err-10;
		
		}
		if(calc_err<0)
		{
		OCR2A = calc_err;
		OCR1AH = 0;
		OCR1AL = calc_err-10;
		}
		if(calc_err==0)
		{
			OCR1AL = 100;
			OCR1AH = 0;
			OCR0A = 100;
		}
	}
}