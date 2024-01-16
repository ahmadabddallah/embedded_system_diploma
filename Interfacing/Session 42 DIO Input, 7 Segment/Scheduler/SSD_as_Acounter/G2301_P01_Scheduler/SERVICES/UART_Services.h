

#ifndef UART_SERVICES_H_
#define UART_SERVICES_H_


#include "UART.h"


void UART_SendInt(u32 num);
u32 UART_ReceiveInt(void);
void UART_ReceiveString(u8*str);
void UART_SendString(u8*str);
void UART_SendString_CS(u8*str);

#endif /* UART_SERVICES_H_ */