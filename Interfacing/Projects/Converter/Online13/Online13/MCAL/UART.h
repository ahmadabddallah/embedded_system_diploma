/*
 * UART.h
 *
 * Created: 30/06/2023 04:31:06 م
 *  Author: ahmed
 */ 


#ifndef UART_H_
#define UART_H_

#include "StdTypes.h"
#include "Utils.h"
#include "MemMap.h"

void UART_Init(void);

void UART_Send(u8 data);


u8 UART_Receive(void);

u8 UART_ReceivePerodic(u8 *pdata);




#endif /* UART_H_ */