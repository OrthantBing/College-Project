#include <REGX51.H>
#include "lcd.c"
#include "serial.c"
sbit buz = P0^2; 
unsigned int tf=0,gf=0;




void serial()interrupt 4
{
	if(RI==1)
	{
		if(SBUF=='1')
		{
			tf=1;			
		}
		else if(SBUF=='2')
		{
			gf=1;
		}
	}
}
void main()
{

	buz = 1;
	lcd_init();
	serial_init();
	lcddatastr("   Coal Mine    ");
	lcdcmd(0xc0);
	lcddatastr("Monitering Sys   ");

	EA=1;
	ES=1;

	P2=0x1f;
	while(1)
	{
	
		while(P2==0x1f);
		if(P2_0==0)
		{
		Transmit('0');
		lcdcmd(0x01);
		lcdcmd(0x80);
		lcddatastr("Forward");
			while(P2!=0x1f);	
		
		}

		if(P2_1==0)
		{
		Transmit('1');
		lcdcmd(0x01);
		lcdcmd(0x80);
		lcddatastr("Backward");
		while(P2!=0x1f);
		}

		if(P2_2==0)
		{
		Transmit('2');
		lcdcmd(0x01);
		lcdcmd(0x80);
		lcddatastr("Left");
		while(P2!=0x1f);
		}

		if(P2_3==0)
		{
		Transmit('3');
		lcdcmd(0x01);
		lcdcmd(0x80);
		lcddatastr("Right");
		while(P2!=0x1f);
		}

		if(P2_4==0)
		{
		Transmit('4');
		lcdcmd(0x01);
		lcdcmd(0x80);
		lcddatastr("Stop");
		while(P2!=0x1f);
		}
			
		delay(50);

	
		if(tf==1)
		{
		lcdcmd(0x01);
		lcdcmd(0x80);
		lcddatastr("Temp Abnormal");
		buz=0;
		tf=0;		
		}
		else if(gf==2)
		{
		lcdcmd(0x01);
		lcdcmd(0x80);
		lcddatastr("Gas Abnormal");		
		buz=0;
		gf=0;
		}
		else
		{
		lcdcmd(0x80);
		lcddatastr("   Coal Mine    ");
		lcdcmd(0xc0);
		lcddatastr("Monitering Sys   ");
		buz=1;
		}
	}	
}