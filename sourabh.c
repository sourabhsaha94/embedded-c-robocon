#include<avr/io.h>  
void main(void)
{
DDRB=0xFF;
TCCR0=0x2C;
while(1)
{
OCR0=0;
}
}
