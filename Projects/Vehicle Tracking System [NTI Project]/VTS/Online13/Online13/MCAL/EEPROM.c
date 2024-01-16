/*
 * EEPROM.c
 *
 * Created: 10/6/2023 4:42:27 AM
 *  Author: ahmed
 */ 


#include "EEPROM.h"


u16 EEPROM_CurrentAddress=0;


void EEPROM_Write(u16 ep_address,u8 ep_data){
	
	while(READ_BIT(EECR,EEWE));
	
	EEAR=ep_address;
	EEDR=ep_data;
	SET_BIT(EECR,EEMWE);
	
	SET_BIT(EECR,EEWE);	
	
	
}

u8 EEPROM_Read(u16 ep_address){
	
	while(READ_BIT(EECR,EEWE));
	
	EEAR=ep_address;
	
	SET_BIT(EECR,EERE);
	
	return EEDR;
	
	
}