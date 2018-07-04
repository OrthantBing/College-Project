#include <REGX51.H>
#include "lcd.c"
#include "serial.c"
sbit buz = P0^0;
sbit msw = P0^1; 
//unsigned int tf=0,gf=0;
void serial()interrupt 4
{	if(RI==1)
	{	if(SBUF=='x')
		{
			//tf=1;
		lcdcmd(0x01);
		lcdcmd(0x80);
		lcddatastr("     Mine   ");
		lcdcmd(0xC0);
		lcddatastr("   Detected  ");
			buz=0;
			delay(65);			
				buz=1;
		}
		else if(SBUF=='y')
		{
			//gf=1;
		 lcdcmd(0x01);
		lcdcmd(0x80);
		lcddatastr("    Human    ");
		lcdcmd(0xC0);
		lcddatastr("  Detected   ");
		buz=0;
		delay(65);			
		buz=1;
	   }
	RI=0;
	}
}
void main()
{		
	lcd_init();
	serial_init();
	lcddatastr("   Military    ");
	lcdcmd(0xc0);
	lcddatastr("   Robot   ");
	delay(50);
	delay(50);
	delay(50);
	buz = 1;
	EA=1;
	ES=1;
	P2=0x1f;
	while(1)
	{
        if(msw==0)
        {
            lcdcmd(0x01);
            lcdcmd(0x80);
            lcddatastr("Manual Mode");
            delay(50);
            delay(50);
            delay(50);
            while(P2==0x1f);
		    if(P2_0==0)
            {
                Transmit('0');
                //lcdcmd(0x01);
                lcdcmd(0xc0);
                lcddatastr("Forward");
                    delay(50);
                    while(P2!=0x1f);
            }
            if(P2_1==0)
            {
                Transmit('1');
                //lcdcmd(0x01);
                lcdcmd(0xc0);
                lcddatastr("Backward");
                    delay(50);
                while(P2!=0x1f);
            }
            if(P2_2==0)
            {
                Transmit('2');
                //lcdcmd(0x01);
                lcdcmd(0xc0);
                lcddatastr("Left");
                    delay(50);
                while(P2!=0x1f);
            }
            if(P2_3==0)
            {
                Transmit('3');
                //lcdcmd(0x01);
                lcdcmd(0xc0);
                lcddatastr("Right");
                    delay(50);
                while(P2!=0x1f);
            }
            if(P2_4==0)
            {
                Transmit('4');
                //lcdcmd(0x01);
                lcdcmd(0xc0);
                lcddatastr("Stop");
                    delay(50);
                while(P2!=0x1f);
            }
            delay(50);
        }
	   if(msw==1)
	   {
            lcdcmd(0x01);
            lcdcmd(0x80);
            lcddatastr("Automatic Mode");
            delay(50);
            delay(50);
            delay(50);
            Transmit('0');
            lcdcmd(0xc0);
            lcddatastr("Forward");
            delay(50);
            delay(50);
	   }		
//		lcdcmd(0x80);
//		lcddatastr("   Military     ");
//		lcdcmd(0xc0);
//		lcddatastr("   Robot        ");
	}	
}
