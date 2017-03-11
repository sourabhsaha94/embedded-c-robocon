#include<avr/io.h>
void main(void)
{
 //DDRB=(1<<PB3);
 DDRB=0xFF;
 TCCR0=(0<<WGM00)|(1<<WGM01)|(1<<COM00)|(0<<COM01)|(1<<CS00)|(0<<CS01)|(1<<CS02);
 
 while(1)
 {
 OCR0=255;
 }
}
