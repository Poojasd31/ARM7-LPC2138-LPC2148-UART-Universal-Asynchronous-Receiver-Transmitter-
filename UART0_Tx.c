#include<lpc21XX.h> 
#include "PLL.h"

#define led1 17
#define sw1  14
#define sw2  15

void delay(int);          
void UART0_Init();
void UART0_Tx(char);

void main (void)
{ 
	PINSEL0|=0x00000000;
	PINSEL1|=0x00000000;
	PINSEL2|=0x00000000;
	IODIR0|=(1<<led1);
  IODIR0|=(0<<sw1);	
	IODIR0|=(0<<sw2);	
	PLL_SET();
	UART0_Init();
    while(1)                
    {
				if((IOPIN0 &(1<<sw1))==0)
				{
						delay(30); 
            UART0_Tx('A');
					
					  
				}	
				if(!(IOPIN0 &(1<<sw2)))
				{
					 delay(30); 
					 UART0_Tx('B');
				
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

void UART0_Tx(char tx)
{
	  U0THR = tx;                  // Transmit character
    while ((U0LSR & (1<<5)) == 0);     // Monitor
    
}

void delay(int t)
{
    int i, j;
    for (i = 0; i < t; i++)
	  {
      for (j = 0; j < 60000; j++)
			{
			}
		}
}
