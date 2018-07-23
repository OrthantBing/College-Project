#include <REGX51.H>
#include "serial.c"
sbit forward = P0^0;
sbit backward = P0^1;
sbit left = P0^2;
sbit right = P0^3;
sbit temp = P2^0;
sbit gas = P2^1;
/*void External_interrupt() interrupt 0{
	Transmit('1');	
} */

void main(){
	unsigned char a;
	serial_init();
	IE = 0x81;
	P0=0x00;
	P2=0xff;
	while(1)
	{																	  
		a=Receive();
		if(a=='0'&&P2==0xff)
		{	
			forward=1;
			delay(65);
			forward=0;	
		}
		else if(a=='1'&&P2==0xff)
		{	
			backward=1;
			delay(65);
			backward=0;					
		}
		else if(a=='2')
		{	
			left=1;
			delay(5);
			left=0;					
		}
		else if(a=='3')
		{	
			right=1;
			delay(5);
			right=0;					
		}
			
		else
		{
		 P0=0x00;
		}

		if(temp==0)
		{
		   	Transmit('1');
		}
		if(gas==0)
		{
		   	Transmit('2');
		}

			
	}	
}