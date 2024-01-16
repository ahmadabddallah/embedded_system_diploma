#include "UART.h"




void UART_Init(void)
{

	//baud rate 9600
	UBRRL=51;
	
	//enable trans,receiver
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
}

void UART_Send(u8 data)
{
	while(!READ_BIT(UCSRA,UDRE));
	UDR=data;
}
u8 UART_Receive(void)
{
	
	while(!READ_BIT(UCSRA,RXC));
	return UDR;
}


