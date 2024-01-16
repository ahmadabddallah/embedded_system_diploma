

#ifndef UART_H_
#define UART_H_

#include "StdTypes.h"
#include "Utils.h"
#include "MemMap.h"


void UART_Init(void);

void UART_Send(u8 data);
u8 UART_Receive(void);





#endif /* UART_H_ */