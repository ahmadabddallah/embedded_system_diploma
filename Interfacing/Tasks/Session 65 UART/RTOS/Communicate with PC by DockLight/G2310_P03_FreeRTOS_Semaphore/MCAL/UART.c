/*
 * UART.c
 *
 *  Created on: Dec 19, 2023
 *      Author: ahmed
 */


#include "UART.h"
/*static void (*UART_RX_Fptr)(void)=NULLPTR;
static void (*UART_TX_Fptr)(void)=NULLPTR;
*/



void UART_Init(void){
	// config of the frame

	//baud rate
	UBRRL_PR=51;

	//normal speed
	CLEAR_BIT(UCSRA_PR,U2X_PR);

	//frame (Stop,data,parity)

	//enable TX  RX
	SET_BIT(UCSRB_PR,TXEN_PR);
	SET_BIT(UCSRB_PR,RXEN_PR);

}


void UART_Send(u8 data){

	while(!READ_BIT(UCSRA_PR,UDRE_PR));
	UDR_PR=data;
}

u8 UART_Receive(void){

	while(!READ_BIT(UCSRA_PR,RXC_PR));
	return UDR_PR;

}

u8 UART_RecievePerodic(u8 *pdata){

	if(READ_BIT(UCSRA_PR,RXC_PR)){
		*pdata=UDR_PR;
		return 1;
	}
	return 0;

}

u8 UART_ReceiveNoBlock(void){
	return UDR_PR;
}

void UART_SendNoBlock(u8 data){
	UDR_PR=data;
}


void RX_InterruptEnable(void){

	SET_BIT(UCSRB_PR,RXCIE_PR);

}
void RX_InterruptDisable(void){
	CLEAR_BIT(UCSRB_PR,RXCIE_PR);
}

void TX_InterruptEnable(void){
	SET_BIT(UCSRB_PR,TXCIE_PR);
}
void TX_InterruptDisable(void){
	CLEAR_BIT(UCSRB_PR,TXCIE_PR);
}


static void(*TX_Fptr)(void)=NULLPTR;
static void(*RX_Fptr)(void)=NULLPTR;

void Set_TX_CallBack(void(*LocaFptr)(void)){

	TX_Fptr=LocaFptr;

}

void Set_RX_CallBack(void(*LocalFptr)(void)){
	RX_Fptr=LocalFptr;
}

ISR(UART_TX_vect_PR){

	if(TX_Fptr!=NULLPTR){
		TX_Fptr();
	}

}

ISR(UART_RX_vect_PR){
	if(RX_Fptr!=NULLPTR){
		RX_Fptr();
	}


}

/*

void UART_RX_InterruptEnable(void){


	SET_BIT(UCSRB_PR,RXCIE_PR);
}
void UART_RX_InterruptDisable(void){

	CLEAR_BIT(UCSRB_PR,RXCIE_PR);
}

void UART_TX_InterruptEnable(void){

	SET_BIT(UCSRB_PR,TXCIE);

}
void UART_TX_InterruptDisable(void){
	CLEAR_BIT(UCSRB_PR,TXCIE);
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

