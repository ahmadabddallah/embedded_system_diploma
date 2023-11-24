/*
 * RGB.h
 *
 * Created: 10/31/2023 12:15:42 AM
 *  Author: ahmed
 */ 


#ifndef RGB_H_
#define RGB_H_

#include "Utils.h"
#include "DIO_Interface.h"
#include "MemMap.h"
#include "Timers.h"
#include "Timers_Services.h"
#include "String.h"


typedef struct{
	u8 Name[8];
	u8 Red_degree;
	u8 Green_degree;
	u8 Blue_degree;
	
}RGB_data;

void RGB_Init(void);

void RGB_SetColor(u8 *Color);

void RGB_CustomeColor(u8 RED,u8 GREEN,u8 BLUE);

extern RGB_data RGB_ARR[9];


#endif /* RGB_H_ */