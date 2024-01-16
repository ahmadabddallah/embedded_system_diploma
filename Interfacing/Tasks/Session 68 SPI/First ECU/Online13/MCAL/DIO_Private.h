/*
 * DIO_Private.h
 *
 * Created: 19/06/2023 11:30:24 م
 *  Author: ahmed
 */ 


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_


extern const DIO_PinStatus_type DIO_PinsStatusArr[TOTAL_PINS];
static void DIO_InitPin(DIO_Pin_type pin,DIO_PinStatus_type status);



#endif /* DIO_PRIVATE_H_ */