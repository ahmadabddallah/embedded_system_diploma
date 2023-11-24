/*
 * EEPROM.h
 *
 * Created: 10/6/2023 4:42:42 AM
 *  Author: ahmed
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "StdTypes.h"
#include "DIO_Interface.h"
#include "MemMap.h"
#include "Utils.h"


extern u16 EEPROM_CurrentAddress;

void EEPROM_Write(u16 ep_address,u8 ep_data);

u8 EEPROM_Read(u16 ep_address);




#endif /* EEPROM_H_ */