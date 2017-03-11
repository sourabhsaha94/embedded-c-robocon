#include<avr/io.h>
void main(void)
{
DDRB=0b10110000;//MOSI SS SCK intialised
SPCR=0b01010001;//clock/16 spi enabled mstr set
while(1)
{
SPDR=0xAA;
while(!(SPSR&0b10000000))//wait for transmission complete
;
}
}
