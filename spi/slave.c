#include<avr/io.h>
void main(void)
{
DDRB=0b01000000;//MISO set as output
DDRA=0xFF;
SPCR=0b01000000;//SPI enabled
while(!(SPSR&0b10000000))//waiting to recieve
;
while(1)
{
PORTA=SPDR;//port a displays content of SPDR
}
}