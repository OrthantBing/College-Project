#include <REGX51.H>

void serial_init()
{
	TMOD=0x20;
	TH1=0xFD;
	SCON=0x50;
	TR1=1;
}

void Transmit(unsigned char value)
{
	SBUF=value;
	while(TI==0	);
	TI=0;
}

unsigned char Receive()
{
	unsigned char i;
	while(RI==0);
	i = SBUF;
	RI = 0;
	return i;
}

void serial_string(unsigned char *s){
	while(*s){
		Transmit(*s);
		s++;
	}
}
/*void serial_interrupt()interrupt 4
{
	if(RI==1) 
	{
		RI=0;
		buzzer = 0;
		lcdcmd(0x81);
		lcddatastr("MINE HAS BEEN ");
		lcdcmd(0xC4);
		lcddatastr("DETECTED");
		delay(1000);
		lcdcmd(0x01);
		buzzer = 1;
	}
} */
