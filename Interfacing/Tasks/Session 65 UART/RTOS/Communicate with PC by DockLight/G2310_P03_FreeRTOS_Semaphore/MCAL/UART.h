/*
 * UART.h
 *
 *  Created on: Dec 19, 2023
 *      Author: ahmed
 */

#ifndef MCAL_UART_H_
#define MCAL_UART_H_


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
















#endif /* MCAL_UART_H_ */
