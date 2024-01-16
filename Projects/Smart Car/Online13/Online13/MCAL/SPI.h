/*
 * SPI.h
 *
 * Created: 21/08/2023 01:13:38 ص
 *  Author: ahmed
 */ 


#ifndef SPI_H_
#define SPI_H_



#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"


#define MASTER	1
#define SlAVE	0	



#define SPI_MODE	MASTER




void SPI_Init(void);

u8 SPI_SendReceive(u8 data);

u8 TransfereByteAsynchCallBack(u8 data);


u8 SPI_ReceivePerodic(u8*pdata);
void SPI_SendNoBlock(u8 data);

#endif /* SPI_H_ */