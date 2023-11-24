/*
 * GPS.h
 *
 * Created: 10/28/2023 6:44:55 PM
 *  Author: ahmed
 */ 


#ifndef GPS_H_
#define GPS_H_

#include "MemMap.h"
#include "Utils.h"
#include "UART.h"
#include "UART_Services.h"
#include "StdTypes.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"

void GPS_Init(void);
void updateGPS(void);


#endif /* GPS_H_ */