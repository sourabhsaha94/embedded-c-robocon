



#include <avr/io.h>
#include <util/delay.h>

#define PS2clk 0
#define PS2cmd 2
#define PS2att 4
#define PS2dat 1
#define PS2PORT PORTC
#define PS2IN PINC

#define SET(x,y) (x|=(1<<y))
#define CLR(x,y) (x&=(~(1<<y)))
#define CHK(x,y) (x & (1<<y))
#define TOG(x,y) (x^=(1<<y)) 
  unsigned char PS2byte;
  unsigned char PS2data4;
  unsigned char PS2data5;
  unsigned char PS2data6;
  unsigned char PS2data7;
  unsigned char PS2data8;
  unsigned char PS2data9;
  unsigned char i;
void ReadGamepad(void);
void config(void);
void analog(void);

int main(void)
{
DDRA=0xFF;
DDRC=0xFD;//0clock1data2command4attention
PORTC=0xFF;
UBRRL=207;//set baud rate 4800 with U2X reset
UCSRB=(1<<TXEN);//transmitter enabled
UCSRC=(0<<UMSEL)|(1<<URSEL)|(0<<USBS)|(3<<UCSZ0);//8bit frame size 1 stop bits
config();
_delay_us(1);
analog();
_delay_us(1);
while(1)
{
ReadGamepad();
_delay_us(5);
while(!(UCSRA&(1<<UDRE)))//till data reg not empty
;
UDR=0x01;
_delay_us(5);
while(!(UCSRA&(1<<UDRE)))//till data reg not empty
;
UDR=PS2data5;
while(!(UCSRA&(1<<UDRE)))//till data reg not empty
;
UDR=PS2data8;
while(!(UCSRA&(1<<UDRE)))//till data reg not empty
;
UDR=PS2data7;
}
}
void ReadGamepad()
{
   SET(PS2PORT,PS2cmd); 
   SET(PS2PORT,PS2clk); 
   CLR(PS2PORT,PS2att); // low enable joystick
  _delay_us(1);
  
   PS2byte=0x01; // first command
   for(i=0;i<8;i++)
   {
      if(CHK(PS2byte,i)) SET(PS2PORT,PS2cmd);
	  else  CLR(PS2PORT,PS2cmd);
      CLR(PS2PORT,PS2clk); 
      SET(PS2PORT,PS2clk); 
   }
   SET(PS2PORT,PS2cmd); 
   _delay_us(1);
   
   PS2byte=0x42; // sec command
   for(i=0;i<8;i++)
   {
      if(CHK(PS2byte,i)) SET(PS2PORT,PS2cmd);
	  else  CLR(PS2PORT,PS2cmd);
      CLR(PS2PORT,PS2clk); 
      SET(PS2PORT,PS2clk); 
   }
   SET(PS2PORT,PS2cmd); 
   _delay_us(1);
   
   for(i=0;i<8;i++)  // 3 byte
   {
      CLR(PS2PORT,PS2cmd);
      CLR(PS2PORT,PS2clk);
      SET(PS2PORT,PS2clk); 
   }
   SET(PS2PORT,PS2cmd); 
   _delay_us(1);
   PS2data4=0;
   for(i=0;i<8;i++)  // 4 byte
   {
      CLR(PS2PORT,PS2cmd);
      CLR(PS2PORT,PS2clk);_delay_us(1);
	  if(CHK(PS2IN,PS2dat)) SET(PS2data4,i); 
      SET(PS2PORT,PS2clk);
   }
   SET(PS2PORT,PS2cmd); 
   _delay_us(1);
   
   PS2data5=0;
   for(i=0;i<8;i++) // 5 byte digital
   {
      CLR(PS2PORT,PS2cmd);
      CLR(PS2PORT,PS2clk);_delay_us(1);
	  if(CHK(PS2IN,PS2dat)) SET(PS2data5,i);
      SET(PS2PORT,PS2clk);
   }
   SET(PS2PORT,PS2cmd); 
   _delay_us(1);
   
   PS2data6=0;
   for(i=0;i<8;i++) // 6 byte x axis right joy
   {
      CLR(PS2PORT,PS2cmd);
      CLR(PS2PORT,PS2clk);_delay_us(1);
	  if(CHK(PS2IN,PS2dat)) SET(PS2data6,i);
      SET(PS2PORT,PS2clk);
   }
   SET(PS2PORT,PS2cmd); 
   _delay_us(1);
   PS2data7=0;
   for(i=0;i<8;i++) // 7 byte y axis of right joy
   {
      CLR(PS2PORT,PS2cmd);
      CLR(PS2PORT,PS2clk);_delay_us(1);
	  if(CHK(PS2IN,PS2dat)) SET(PS2data7,i);
      SET(PS2PORT,PS2clk);
   }
   SET(PS2PORT,PS2cmd); 
   _delay_us(1);
   PS2data8=0;
   for(i=0;i<8;i++) // 8 byte x axis of left joy
   {
      CLR(PS2PORT,PS2cmd);
      CLR(PS2PORT,PS2clk);_delay_us(1);
	  if(CHK(PS2IN,PS2dat)) SET(PS2data8,i);
      SET(PS2PORT,PS2clk);
   }
   SET(PS2PORT,PS2cmd); 
   _delay_us(1);
   PS2data9=0;
   for(i=0;i<8;i++) // 9 byte y axis of left joy
   {
      CLR(PS2PORT,PS2cmd);
      CLR(PS2PORT,PS2clk);_delay_us(1);
	  if(CHK(PS2IN,PS2dat)) SET(PS2data9,i);
      SET(PS2PORT,PS2clk);
   }
   SET(PS2PORT,PS2cmd); 
   _delay_us(1);
   SET(PS2PORT,PS2att); // HI disable joystick
}

void config()	//enter config mode
{
	SET(PS2PORT,PS2cmd); 
   SET(PS2PORT,PS2clk); 
   CLR(PS2PORT,PS2att); // low enable joystick
  _delay_us(1);
  PS2byte=0x01;		//byte1
	
	for(i=0;i<8;i++)
   {
      if(CHK(PS2byte,i)) SET(PS2PORT,PS2cmd);
	  else  CLR(PS2PORT,PS2cmd);
      CLR(PS2PORT,PS2clk); 
      SET(PS2PORT,PS2clk); 
   }
   SET(PS2PORT,PS2cmd); 
   _delay_us(1);
	
	
	PS2byte=0x43; // sec command
   for(i=0;i<8;i++)
   {
      if(CHK(PS2byte,i)) SET(PS2PORT,PS2cmd);
	  else  CLR(PS2PORT,PS2cmd);
      CLR(PS2PORT,PS2clk); 
      SET(PS2PORT,PS2clk); 
   }
   SET(PS2PORT,PS2cmd); 
   _delay_us(1);
	
	
	
		
	   for(i=0;i<8;i++)  // 3 byte
   {
      CLR(PS2PORT,PS2cmd);
      CLR(PS2PORT,PS2clk);
      SET(PS2PORT,PS2clk); 
   }
   SET(PS2PORT,PS2cmd); 

	
	
	PS2byte=0x01;		//byte1
	
	for(i=0;i<8;i++)
   {
      if(CHK(PS2byte,i)) SET(PS2PORT,PS2cmd);
	  else  CLR(PS2PORT,PS2cmd);
      CLR(PS2PORT,PS2clk); 
      SET(PS2PORT,PS2clk); 
   }
   SET(PS2PORT,PS2cmd); 
   _delay_us(1);
	
	
   
	   for(i=0;i<8;i++)  // 3 byte
   {
      CLR(PS2PORT,PS2cmd);
      CLR(PS2PORT,PS2clk);
      SET(PS2PORT,PS2clk); 
   }
   SET(PS2PORT,PS2cmd);
	_delay_us(1);
	SET(PS2PORT,PS2att);

}

void analog()	//to set permanent  analog mode
{
	
	SET(PS2PORT,PS2cmd); 
   SET(PS2PORT,PS2clk); 
   CLR(PS2PORT,PS2att); // low enable joystick
  _delay_us(1);
  PS2byte=0x01;		//byte1
	for(i=0;i<8;i++)
   {
      if(CHK(PS2byte,i)) SET(PS2PORT,PS2cmd);
	  else  CLR(PS2PORT,PS2cmd);
      CLR(PS2PORT,PS2clk); 
      SET(PS2PORT,PS2clk); 
   }
   SET(PS2PORT,PS2cmd); 
   _delay_us(1);


	
	
	PS2byte=0x43; // sec command
   for(i=0;i<8;i++)
   {
      if(CHK(PS2byte,i)) SET(PS2PORT,PS2cmd);
	  else  CLR(PS2PORT,PS2cmd);
      CLR(PS2PORT,PS2clk); 
      SET(PS2PORT,PS2clk); 
   }
   SET(PS2PORT,PS2cmd); 
   _delay_us(1);
	
	
	
		
	
	   for(i=0;i<8;i++)  // 3 byte
   {
      CLR(PS2PORT,PS2cmd);
      CLR(PS2PORT,PS2clk);
      SET(PS2PORT,PS2clk); 
   }
   SET(PS2PORT,PS2cmd);
	_delay_us(1);
	
	PS2byte=0x01;		//byte1
	
	for(i=0;i<8;i++)
   {
      if(CHK(PS2byte,i)) SET(PS2PORT,PS2cmd);
	  else  CLR(PS2PORT,PS2cmd);
      CLR(PS2PORT,PS2clk); 
      SET(PS2PORT,PS2clk); 
   }
   SET(PS2PORT,PS2cmd); 
   _delay_us(1);
	
	
   
	PS2byte = 0x03;			//byte4
	for(i=0;i<8;i++)
   {
      if(CHK(PS2byte,i)) SET(PS2PORT,PS2cmd);
	  else  CLR(PS2PORT,PS2cmd);
      CLR(PS2PORT,PS2clk); 
      SET(PS2PORT,PS2clk); 
   }
   SET(PS2PORT,PS2cmd); 
   _delay_us(1);

	SET(PS2PORT,PS2att);

}
