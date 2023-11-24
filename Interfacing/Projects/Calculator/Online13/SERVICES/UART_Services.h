/*
 * UART_Services.h
 *
 * Created: 30/06/2023 07:55:56 م
 *  Author: ahmed
 */ 

#include "StdTypes.h"
#define F_CPU 8000000
#include "util/delay.h"
#include "UART.h"

#ifndef UART_SERVICES_H_
#define UART_SERVICES_H_
	
void UART_SendString(u8 *str); 
void UART_ReceiveString(u8 *str);

void UART_SendNumber(u32 num);

u32 UART_ReceiveNumber(void);



//this is an interview question 
void UART_SendStringCheckSum(u8 *str); 
u8 UART_ReceiveStringCheckSum(u8 *str);

	 	
#endif /* UART_SERVICES_H_ */