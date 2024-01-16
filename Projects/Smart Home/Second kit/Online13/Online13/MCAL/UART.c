/*
 * UART.c
 *
 * Created: 30/06/2023 04:30:48 م
 *  Author: ahmed
 */ 

#include "UART.h"

/*static void (*UART_RX_Fptr)(void)=NULLPTR;
static void (*UART_TX_Fptr)(void)=NULLPTR;
*/



void UART_Init(void){
	// config of the frame 
	
	//baud rate
	UBRRL=51;
	
	//normal speed 
	CLR_BIT(UCSRA,U2X);
	
	//frame (Stop,data,parity)

	//enable TX  RX
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

u8 UART_RecievePerodic(u8 *pdata){
	
	if(READ_BIT(UCSRA,RXC)){
		*pdata=UDR;
		return 1;
	}
	return 0;
	
}

u8 UART_ReceiveNoBlock(void){
	return UDR;
}

void UART_SendNoBlock(u8 data){
	UDR=data;
}


void RX_InterruptEnable(void){
	
	SET_BIT(UCSRB,RXCIE);
	
}
void RX_InterruptDisable(void){
	CLR_BIT(UCSRB,RXCIE);
}

void TX_InterruptEnable(void){
	SET_BIT(UCSRB,TXCIE);
}
void TX_InterruptDisable(void){
	CLR_BIT(UCSRB,TXCIE);
}


static void(*TX_Fptr)(void)=NULLPTR;
static void(*RX_Fptr)(void)=NULLPTR;

void Set_TX_CallBack(void(*LocaFptr)(void)){
	
	TX_Fptr=LocaFptr;	
	
}

void Set_RX_CallBack(void(*LocalFptr)(void)){
	RX_Fptr=LocalFptr;
}

ISR(UART_TX_vect){
		
	if(TX_Fptr!=NULLPTR){
		TX_Fptr();
	}
	
}

ISR(UART_RX_vect){
	DIO_TogglePin(PINC0);
	if(RX_Fptr!=NULLPTR){
		RX_Fptr();
	}
	
	
}

/*

void UART_RX_InterruptEnable(void){
	
	
	SET_BIT(UCSRB,RXCIE);
}
void UART_RX_InterruptDisable(void){
	
	CLR_BIT(UCSRB,RXCIE);
}

void UART_TX_InterruptEnable(void){
	
	SET_BIT(UCSRB,TXCIE);
	
}
void UART_TX_InterruptDisable(void){
	CLR_BIT(UCSRB,TXCIE);
}



void UART_RX_SetCallBack(void(*LocalFptr)(void)){
	UART_RX_Fptr=LocalFptr;
	
}
void UART_TX_SetCallBack(void(*LocalFptr)(void)){
	UART_TX_Fptr=LocalFptr;
	
}

ISR(UART_RX_vect){
	
	if(UART_RX_Fptr!=NULLPTR){
		UART_RX_Fptr();
	}
	
}

ISR(UART_TX_vect){
	
	if(UART_TX_Fptr!=NULLPTR){
		UART_TX_Fptr();
	}
	
}


*/