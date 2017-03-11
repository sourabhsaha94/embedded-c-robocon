
#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>
#include"avrlibdefs.h"

unsigned chari,ps2byte,ps2cmd,ps2clk,ps2data4,ps2data5,ps2data6,ps2data7,ps2data8,ps2data9;
int i;

#define ps2clk 0
#define ps2cmd 2
#define ps2att 4
#define ps2dat 1
#define ps2port PORTA
#define ps2in PINA

void readgamepad()
{
	
	sbi(ps2port,ps2cmd);
	sbi(ps2port,ps2clk);
	cbi(ps2port,ps2att);
	
	_delay_us(30);
	
	ps2byte = 0x01;			//byte1
	
	for(i=0;i<8;i++)		
	{
		if(ps2byte&(_BV(i)))
			sbi(ps2port,ps2cmd);
		else 
			cbi(ps2port,ps2cmd);
		cbi(ps2port,ps2clk); 
		_delay_us(1); 			
		sbi(ps2port,ps2clk); 
		_delay_us(1); 	
	}
	sbi(ps2port,ps2cmd); 


	
	
	ps2byte = 0x42;			//byte2
	
	for(i=0;i<8;i++)
	{
		if(ps2byte&(_BV(i)))
			sbi(ps2port,ps2cmd);
		else 
			cbi(ps2port,ps2cmd);
		cbi(ps2port,ps2clk); 
		_delay_us(1); 			
		sbi(ps2port,ps2clk); 
		_delay_us(1); 	
	}
	sbi(ps2port,ps2cmd); 
	
	
	
		
	for(i=0;i<8;i++)		//byte3
	{	
		cbi(ps2port,ps2cmd);
		cbi(ps2port,ps2clk);
		_delay_us(1); 	 
		sbi(ps2port,ps2clk); 
		_delay_us(1); 	
		
	}
	sbi(ps2port,ps2cmd); 
	
	
	ps2data4=0;
	for(i=0;i<8;i++)  // 4 byte
	{
		cbi(ps2port,ps2cmd);
		cbi(ps2port,ps2clk);
		_delay_us(1);
		if((ps2in&(0x02))==0x00)
			cbi(ps2data4,i); 
		else
			sbi(ps2data4,i); 
		sbi(ps2port,ps2clk);
		_delay_us(1); 	
	}
	sbi(ps2port,ps2cmd); 
	
	
	
   
	ps2data5=0;
	for(i=0;i<8;i++) // 5 byte
	{
		cbi(ps2port,ps2cmd);
		cbi(ps2port,ps2clk); 
		_delay_us(1);  
			
		if((ps2in&(0x02))==0x00)
			cbi(ps2data5,i); 
		else
			sbi(ps2data5,i); 
		sbi(ps2port,ps2clk);
		_delay_us(1); 	
	}
	sbi(ps2port,ps2cmd); 
	
	
	
	
	ps2data6=0;
	for(i=0;i<8;i++) // 6byte
	{
		cbi(ps2port,ps2cmd);
		cbi(ps2port,ps2clk); 
		_delay_us(1);  
			
		if((ps2in&(0x02))==0x00)
			cbi(ps2data6,i); 
		else
			sbi(ps2data6,i); 
		sbi(ps2port,ps2clk);
		_delay_us(1); 	
	}
	sbi(ps2port,ps2cmd); 
	
	
	
	
	ps2data7=0;
	for(i=0;i<8;i++) // 7 byte
	{
		cbi(ps2port,ps2cmd);
		cbi(ps2port,ps2clk); 
		_delay_us(1);  
			
		if((ps2in&(0x02))==0x00)
			cbi(ps2data7,i); 
		else
			sbi(ps2data7,i); 
		sbi(ps2port,ps2clk);
		_delay_us(1); 	
	}
	sbi(ps2port,ps2cmd); 
	

	
	
	ps2data8=0;
	for(i=0;i<8;i++) // 8 byte
	{
		cbi(ps2port,ps2cmd);
		cbi(ps2port,ps2clk); 
		_delay_us(1);  
			
		if((ps2in&(0x02))==0x00)
			cbi(ps2data8,i); 
		else
			sbi(ps2data8,i); 
		sbi(ps2port,ps2clk);
		_delay_us(1); 	
	}
	sbi(ps2port,ps2cmd); 
	

	
	
	ps2data9=0;
	for(i=0;i<8;i++) // 9 byte
	{
		cbi(ps2port,ps2cmd);
		cbi(ps2port,ps2clk); 
		_delay_us(1);  
			
		if((ps2in&(0x02))==0x00)
			cbi(ps2data9,i); 
		else
			sbi(ps2data9,i); 
		sbi(ps2port,ps2clk);
		_delay_us(1); 	
	}
	sbi(ps2port,ps2cmd); 
	
	
	
	sbi(ps2port,ps2att);
}

void main()
{
	DDRA = 0xFD;
	PORTA = 0xFF;
	DDRK = 0xFF;
	DDRF = 0xFF;
	
	DDRB = 0xFF;			//motor output
TCCR1A = 0x81;
TCCR1B = 0x01;
TCCR1C = 0x00;
TCCR2A = 0x81;
TCCR2B = 0x01;
DDRC = 0xFF;			//motor output
	
	
unsigned char right,left;
int gear = 1;
int pre=0,next=0,pre1=0,next1=0;
	while(1)
	{
	readgamepad();
	_delay_us(10);
	PORTK = gear;
	PORTF = gear;
	
	right = ps2data9;
	left = ps2data7;
	
	/*if((ps2data4&0x80)==0x80)
		PORTC |= 0x0A;
		
	else
		PORTC &= 0xF5;
		*/
		
	if((ps2data5&0x01)==0x01)
		next = 1;
	else
		next = 0;
		
	
	if((next==0)&&(pre==1))
	{
		gear++;
		if(gear==6)
			gear=5;
		
	}
		pre=next;
	
	if((ps2data5&0x04)==0x04)
		next1 = 1;
	else
		next1 = 0;
	
	if((next1==0)&&(pre1==1))
	{
		gear--;
		if(gear==0)
			gear=1;
		
	}
		pre1=next1;
	
	if((right-127)>=0)
	{
		PORTC &= 0xFB;
		right=right-127;
	}
	else
	{
		PORTC |= 0x04;
		right = 127-right;
	}
	
	if((left-127)>=0)
	{
		PORTC &= 0xFE;
		left=left-127;
	}
	else
	{
		PORTC |= 0x01;
		left = 127-left;
	}
	
	
	OCR1A=right/gear;
	OCR2A=left/gear;
	
	_delay_ms(1);
	}
	}