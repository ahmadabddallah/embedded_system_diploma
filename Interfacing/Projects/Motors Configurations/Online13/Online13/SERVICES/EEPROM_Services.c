/*
 * EEPROM_Services.c
 *
 * Created: 10/6/2023 5:23:34 AM
 *  Author: ahmed
 */ 


#include "EEPROM.h"
#include "EEPROM_Services.h"

static volatile u8*Localstr;


void EEPROM_Erase(void){
	for(u16 i=0;i<1024;i++){
		EEPROM_Write(i,0xff);
	}
	EEPROM_CurrentAddress=0;
}

void EEPROM_StoreString_Sync(u8 *str){
	
	for(u8 i=0;str[i];i++){
		EEPROM_Write(EEPROM_CurrentAddress++,str[i]);
	}
	
}


void EEPROM_StoreString_ASync(u8 *str){
	//enable EEPROM interrupt
	Localstr=str;
	SET_BIT(EECR,EERIE);
	
	
	
	
}



ISR(EE_RDY_vect){
	static u8 i=0;
	if(Localstr[i]=='#'){
		CLR_BIT(EECR,EERIE);
		return;
	}
	EEPROM_Write(EEPROM_CurrentAddress++,Localstr[i++]);
	
	
	
}