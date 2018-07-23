#include <REGX51.H>
sbit RS = P3^5; 
sbit RW = P3^6; 
sbit EN = P3^7;

void delay(unsigned int value)
{
	unsigned int i, j;
	for(i=0;i<=value;i++)
	{
		for(j=0;j<=1000;j++)
		{
		}
	}
}
void lcdcmd(unsigned char value)
{
	P1 = value;
	RS = 0;
	RW = 0;
	EN = 1;
	delay(1);
	EN = 0;
}

void lcddatastr(unsigned char *value)
{
	unsigned int i=0;
	while(value[i] != '\0')
	{
		P1 = value[i];
		i++;
		RS = 1;
		RW = 0;
		EN = 1;
		delay(1);
		EN = 0;
	}
}

void lcddata(unsigned char value)
{
	P1 = value;
	RS = 1;
	RW = 0;
	EN = 1;
	delay(1);
	EN = 0;
}

void lcd_init(){
	lcdcmd(0x38);
	lcdcmd(0x0C);
	lcdcmd(0x80);
}