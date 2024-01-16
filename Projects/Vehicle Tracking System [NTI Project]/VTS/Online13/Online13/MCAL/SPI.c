/*
 * SPI.c
 *
 * Created: 21/08/2023 01:13:25 ص
 *  Author: ahmed
 */ 

#include "SPI.h"

static void (*SPI_Fptr)(int,int)=NULLPTR; 




void SPI_Init(void){
	//SLAVE OR MASTER
	#if SPI_MODE == MASTER
	SET_BIT(SPCR,MSTR);
	//clock
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

ISR(SPI_STC_vect){
	
	SPI_Fptr=TransfereByteAsynchCallBack;
	
}