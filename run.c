#include <REGX51.H>
void delay(unsigned int value)
{	unsigned int i, j;
	for(i=0;i<=value;i++){
		for(j=0;j<=1000;j++){
		}
	}
}
void serial_init()
{
	TMOD=0x20;
	TH1=0xFD;
	SCON=0x50;
	TR1=1;
}
void Transmit(unsigned char value)
{	SBUF=value;
	while(TI==0);
	TI=0;
}
unsigned char Receive()
{	unsigned char i;
	while(RI==0);
	i = SBUF;
	RI = 0;
	return i;
}
void serial_string(unsigned char *s){
	while(*s)
{		Transmit(*s);
		s++;
	}
}
