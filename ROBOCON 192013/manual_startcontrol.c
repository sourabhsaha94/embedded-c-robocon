
 unsigned char i;
  unsigned char PS2byte;
  unsigned char PS2data4;
  unsigned char PS2data5;

#define PS2clk 3 // bit 3
#define PS2cmd 2 // bit 2
#define PS2att 1 // bit 1
#define PS2dat 0 // bit 0
#define PS2PORT PORTB // change to fit your port hardware
#define PS2IN PINB    // change to fit your port hardware
int main(void)
{

}
void ReadGamepad()
{
   SET(PS2PORT,PS2cmd); 
   SET(PS2PORT,PS2clk); 
   CLR(PS2PORT,PS2att); // low enable joystick

   Delay(1); // one uS delay CPU timed at the clock speed your AVR is running.
   PS2byte=0x01; // first command
   for(i=0;i<8;i++)
   {
      if(CHK(PS2byte,i)) SET(PS2PORT,PS2cmd);
      else CLR(PS2PORT,PS2cmd);
      CLR(PS2PORT,PS2clk); //Delay(1); if you run faster then 8Mhz you might need a small delay
      SET(PS2PORT,PS2clk); 
   }
   SET(PS2PORT,PS2cmd); 

   Delay(1);
   PS2byte=0x42; // sec command
   for(i=0;i<8;i++)
   {
      if(CHK(PS2byte,i)) SET(PS2PORT,PS2cmd);
      else CLR(PS2PORT,PS2cmd);
      CLR(PS2PORT,PS2clk); //Delay(1); if you run faster then 8Mhz you might need a small delay
      SET(PS2PORT,PS2clk); 
   }
   SET(PS2PORT,PS2cmd); 

   Delay(1);
   for(i=0;i<8;i++)  // 3 byte
   {
      CLR(PS2PORT,PS2cmd);
      CLR(PS2PORT,PS2clk); //Delay(1); if you run faster then 8Mhz you might need a small delay
      SET(PS2PORT,PS2clk); 
   }
   SET(PS2PORT,PS2cmd); 

   Delay(1);
   PS2data4=0;
   for(i=0;i<8;i++)  // 4 byte
   {
      CLR(PS2PORT,PS2cmd);
      CLR(PS2PORT,PS2clk); Delay(1); // this delay is needed even at 8MHz!!
      if(CHK(PS2IN,PS2dat)) SET(PS2data4,i); 
      SET(PS2PORT,PS2clk);
   }
   SET(PS2PORT,PS2cmd); 

   Delay(1);
   PS2data5=0;
   for(i=0;i<8;i++) // 5 byte
   {
      CLR(PS2PORT,PS2cmd);
      CLR(PS2PORT,PS2clk); Delay(1);  // this delay is needed even at 8MHz!!
      if(CHK(PS2IN,PS2dat)) SET(PS2data5,i);
      SET(PS2PORT,PS2clk);
   }
   SET(PS2PORT,PS2cmd); 
   Delay(1);
   SET(PS2PORT,PS2att); // HI disable joystick
}
/*	
void config()	//enter config mode
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


	
	
	ps2byte = 0x43;			//byte2
	
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
	
	
	ps2byte = 0x01;			//byte4
	
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
	
	
	
   
	ps2data5=0;
	for(i=0;i<8;i++) // 5 byte
	{
		cbi(ps2port,ps2cmd);
		cbi(ps2port,ps2clk);
		_delay_us(1); 	 
		sbi(ps2port,ps2clk); 
		_delay_us(1); 	
	}
	sbi(ps2port,ps2cmd); 
	
	sbi(ps2port,ps2att);

}

void analog()	//to set permanent  analog mode
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


	
	
	ps2byte = 0x44;			//byte2
	
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
	
	
	ps2byte = 0x01;			//byte4 to set analog mode
	
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
	
	
	
   
	ps2byte = 0x03;			//byte4
	
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
	
	sbi(ps2port,ps2att);

}
*/
