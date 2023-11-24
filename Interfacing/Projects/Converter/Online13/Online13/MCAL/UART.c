/*
 * UART.c
 *
 * Created: 30/06/2023 04:30:48 م
 *  Author: ahmed
 */ 

#include "UART.h"


void UART_Init(void){
	// frame 8 BIT NO PARITY 1 STOP BIT
	
	
	CLR_BIT(UCSRA,U2X);//NORMAL SPEED
	
	
	//baud rate	9600 for 8MHz Normal SPEED
	UBRRL=51;
	// ENABLE
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
	
	
}

void UART_Send(u8 data){

	while(!READ_BIT(UCSRA,UDRE));
	UDR=data;

}



u8 UART_Receive(void){
	
	while(!READ_BIT(UCSRA,RXC));
	return UDR;
	
	
}


u8 UART_ReceivePerodic(u8 *pdata){
	
	if(READ_BIT(UCSRA,RXC)){
		
		*pdata=UDR;
		return 1;
		
		
	}
	else{
		
		return 0;
		
	}
	
	
	
	
}



