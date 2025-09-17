#include <LPC21XX.h>
#include "PLL.h"

#define LED 17 //0.17

void delay(int);
void UART0_Init();
unsigned char UART_Rx();


void main()
{
	unsigned char rx_data;
	PINSEL1 = 0X00000000;
	IODIR0 |= (1<<LED); //as an output
	
  PLL_SET(); //Set-up PLL
	UART0_Init(); //Initialize UART
	
	
	
	while(1)
	{
		rx_data = UART_Rx(); //Receive data
		
		if(rx_data == 'Y')
		{
			IOSET0 = (1<<LED);
			delay(500);
			IOCLR0 = (1<<LED);
			delay(500);
		}
		
	}
	
}

void UART0_Init()
{
	  PINSEL0 |= 0x00000005;       // UART0 TXD (P0.0), RXD (P0.1)
	  IODIR0 |= (1<<0);           //AS an output
	  IODIR0 &= ~(1<<1);          //as an input
	  
    U0LCR = 0x83;                // Enable DLAB, 8-bit word length
    U0DLM = 0x00;
    U0DLL = 0xC3;                // 9600 baud rate 
	  U0LCR = 0X03;                //Disable DLAB
}

unsigned char UART_Rx()
{
	while((U0LSR & (1<<0 )) == 0); //Monitor till it is fulled
	return U0RBR;
}

void delay(int t)
{
	int i,j;
	for(i=0;i<t;i++)
	{
		for(j=0;j<60000;j++)
		{
			
		}
	}
}
