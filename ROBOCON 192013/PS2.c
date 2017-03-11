
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
#define ps2port PORTC
#define ps2in PINC

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
	

	
	
	ps2data5=0;
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
	

	
	
	ps2data5=0;
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
	DDRC = 0xFD;
	PORTC = 0xFF;
	DDRA = 0xFF;
	DDRB = 0xFF;
	
	

	while(1)
	{
	readgamepad();
	_delay_us(10);
	PORTA = ps2data7;
	PORTB = ps2data9;
	
	
	_delay_ms(1);
	}
	}