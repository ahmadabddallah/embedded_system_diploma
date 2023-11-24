/*
 * EEPROM_Services.h
 *
 * Created: 10/6/2023 5:23:20 AM
 *  Author: ahmed
 */ 


#ifndef EEPROM_SERVICES_H_
#define EEPROM_SERVICES_H_

#include "EEPROM.h"
#include "StdTypes.h"

void EEPROM_Erase(void);
void EEPROM_StoreString_Sync(u8 *str);

void EEPROM_StoreString_ASync(u8 *str);



#endif /* EEPROM_SERVICES_H_ */