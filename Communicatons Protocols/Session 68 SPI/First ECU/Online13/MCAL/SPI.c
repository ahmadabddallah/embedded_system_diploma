/*
 * SPI.c
 *
 * Created: 21/08/2023 01:13:25 ص
 *  Author: ahmed
 */ 

#include "SPI.h"

static void (*ISR_SPI)(void)=NULLPTR; 




void SPI_Init(void){
	//SLAVE OR MASTER
	#if SPI_MODE == MASTER
	SET_BIT(SPCR,MSTR);
	
	#else
	CLR_BIT(SPCR,MSTR);
	#endif
	
	//SPI	Enable
	SET_BIT(SPCR,SPE);
}




u8 SPI_SendReceive(u8 data){
	//write buffer
	SPDR=data;
	while(!READ_BIT(SPSR,SPIF));
	
	//received
	//read buffer 
	
	return SPDR;
	
	
}


u8 SPI_ReceivePerodic(u8*pdata){
	if(READ_BIT(SPSR,SPIF)){
		*pdata=SPDR;
		return 1;
		
	}
	return 0;
	
	
}

void SPI_SendNoBlock(u8 data){
	
	SPDR=data;
	
}
u8 SPI_Receive_NoBlock(void){
	return SPDR;
}

ISR(SPI_STC_vect){
	if(ISR_SPI!=NULLPTR){
		ISR_SPI();
	}
	
	
}
void SPI_SetCallBack(void(*Fptr_SPI)(void)){
	if(Fptr_SPI!=NULLPTR){
		ISR_SPI=Fptr_SPI;
	}
	
}

void SPI_Interrupt_Enable(void){
	SET_BIT(SPCR,SPIE);
}
void SPI_Interrupt_Disable(void){
	CLR_BIT(SPCR,SPIE);
}