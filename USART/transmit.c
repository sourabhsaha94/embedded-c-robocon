#include<avr/io.h>
void main(void)
{
DDRD=0xFF;
DDRA=0x00;
UBRRL=207;//set baud rate 4800 with U2X reset
UCSRB=(1<<TXEN);//transmitter enabled
UCSRC=(0<<UMSEL)|(1<<URSEL)|(0<<USBS)|(3<<UCSZ0);//8bit frame size 1 stop bits
while(1)
{
while(!(UCSRA&(1<<UDRE)))//till data reg not empty
;
UDR=0xAA;
}
}