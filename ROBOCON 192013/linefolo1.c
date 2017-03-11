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

int max = 120;
unsigned char input;
int prop,diff,inte,lprop,flag1;
int kp = 15;
int ki = 10;
int kd = 0;
int calc_err;
int x;

while(1)
	{	
		_delay_ms(1);
		input = PINL&0x7F;
		switch(input)
		{
		case 1:			//0000001
			x=12;
			break;
		case 2:			//0000010
			x=8;
			break;
		case 3:			//0000011
			x=10;
			break;
		case 4:			//0000100
			x=3;
			break;
		case 6:			//0000110
			x=6;
			break;
		case 7:			//0000111
			x=9;
			break;
		case 8:			//0001000
			x=0;
			break;
		case 12:		//0001100
			x=1;
			break;
		case 14:		//0001110
			x=2;
			break;	
		case 16:		//0010000
			x=-3;
			break;
		case 24:		//0011000
			x=-1;
			break;
		case 28:		//0011100
			x=-0;
			break;
		case 32:		//0100000
			x=-8;
			break;
		case 48:		//0110000
			x=-6;
			break;
		case 56:		//0111000
			x=-2;
			break;
		case 64:		//1000000
			x=-12;
			break;
		case 96:		//1100000
			x=-10;
			break;
		case 112:		//1110000
			x=-9;
			break;
		case 15:		//0001111
			x=15;
			break;
		case 31:		//0011111
			x=15;
			break;
		case 63:		//0111111
			x=15;
			break;
		case 120:		//1111000
			x=-15;
			break;
		case 124:		//1111100
			x=-15;
			break;
		case 126:		//1111110
			x=-15;
			break;
				
	
		
		}
		
		
		prop = x; 
		inte = inte + prop;
		diff = prop - lprop;
		lprop = prop;
		calc_err = (kp*prop)+(ki*(inte/1000))+(kd*diff);
		PORTC = 0x05;
		if(calc_err>max)
			calc_err=max-1;
		if(calc_err<-max)
			calc_err=-(max-1);
		
		if(calc_err>0)
		{	
			if((max+calc_err)>250)
				OCR2A = max;
			else
				OCR2A = max+calc_err;
			OCR1AH = 0;
			OCR1AL = max-calc_err;
			
		
		}
		if(calc_err<0)
		{
			calc_err = -calc_err;
			if((max+calc_err)>250)
				OCR1AL = max;
			else
				OCR1AL = max+calc_err;
			
			
			
			OCR1AH = 0;
			OCR2A = max-calc_err;
			
		
		}
		if(calc_err==0)
		{
			OCR1AL = max;
			OCR1AH = 0;
			OCR2A = max;
		}
	}
}