/*
 * Sensors.c
 *
 * Created: 07/07/2023 11:11:34 م
 *  Author: ahmed
 */ 

#include "StdTypes.h"
#include "ADC_Interface.h"
#include "Sensors_Interface.h"
#include "Sensors_Cfg.h"

u16 TEMP_Read(void){
	
	u16 volt=ADC_ReadVolt(LM35_CH);
	u16 temp;
	temp=volt;
	
	return temp;
	
}