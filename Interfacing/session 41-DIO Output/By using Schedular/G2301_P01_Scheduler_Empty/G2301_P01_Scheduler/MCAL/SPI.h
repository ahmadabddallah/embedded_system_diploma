
#ifndef SPI_H_
#define SPI_H_


#include "MemMap.h"
#include "Utils.h"
#include "StdTypes.h"


void SPI_InitMaster(void);
void SPI_InitSlave(void);
u8 SPI_SendReceive(u8 data);
u8 SPI_ReceivePeriodicChecking(u8 *pdata);


#endif /* SPI_H_ */