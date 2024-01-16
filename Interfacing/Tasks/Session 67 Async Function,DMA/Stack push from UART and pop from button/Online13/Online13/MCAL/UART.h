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
#include "DIO_Interface.h"

void UART_Init(void);

void UART_Send(u8 data);
	
u8 UART_Receive(void);


u8 UART_RecievePerodic(u8 *data);

void UART_SendNoBlock(u8 data);

u8 UART_ReceiveNoBlock(void);

void RX_InterruptEnable(void);
void RX_InterruptDisable(void);

void TX_InterruptEnable(void);
void TX_InterruptDisable(void);

void Set_TX_CallBack(void(*LocalFptr)(void));

void Set_RX_CallBack(void(*LocalFptr)(void));

















/*
void UART_RX_InterruptEnable(void);
void UART_RX_InterruptDisable(void);

void UART_TX_InterruptEnable(void);
void UART_TX_InterruptDisable(void);

void UART_RX_SetCallBack(void(*LocalFptr)(void));
void UART_TX_SetCallBack(void(*LocalFptr)(void));

*/






#endif /* UART_H_ */