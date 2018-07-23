#include <REGX51.H>
#include "serial.c"
sbit forward = P0^0;
sbit backward = P0^1;
sbit left = P0^2;
sbit right = P0^3;
sbit mine = P3^2;
sbit pir = P3^3;
sbit ir = P2^0;
void External_interrupt() interrupt 0
{
	Transmit('x');
	EX0=0;	
}
void Externa2_interrupt() interrupt 2
{
	Transmit('y');
	EX1=0;	
} 

void main()
{
	unsigned char a;
	serial_init();
    EA=1;
	EX0=1;
	EX1=1;
	P0=0x00;
	while(1)
	{																	  
		a=Receive();
		if(a=='0')
		{	
		if(ir==0)
		{
		    forward=0;
			backward=0;
			left=0;
			right=0;
		}
		else
		{
			forward=1;
			backward=0;
			left=1;
			right=0;
	   }
		}
		else if(a=='1')
		{	
			forward=0;
			backward=1;
			left=0;
			right=1;
		}
		else if(a=='2')
		{	
			forward=0;
			backward=0;
			left=1;
			right=0;
			delay(15);
			left=0;					
		}
		else if(a=='3')
		{	
			forward=1;
			backward=0;
			left=0;
			right=0;
			delay(15);
		    forward=0;					
		}
		else if(a=='4')
		{
		    forward=0;
			backward=0;
			left=0;
			right=0;
		}
		EX0=1;
		EX1=1;
	}	
}