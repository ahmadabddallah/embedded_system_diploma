/*
 * WIFI_Interface.h
 *
 * Created: 01/07/2023 05:19:44 م
 *  Author: ahmed
 */ 


#ifndef WIFI_INTERFACE_H_
#define WIFI_INTERFACE_H_

#include "StdTypes.h"
#include "MemMap.h"

void WIFI_Init();
void WIFI_voidTest_Connection(void);

void WIFI_voidConnectToSSID(u8 Copy_u8SSID,u8 Copy_u8PASS);

void WIFI_voidSendData(u8* Copy_u8str);

u8 WIFI_u8ReceiveData(void);

void WIFI_voidConnectToServer(u8 Copy_u8Server,u8 Copy_u8PORT);





#endif /* WIFI_INTERFACE_H_ */