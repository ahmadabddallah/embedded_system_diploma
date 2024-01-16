/*
 * SSD.c
 *
 * Created: 11/27/2023 2:29:08 AM
 *  Author: ahmed
 */ 


#include "SSD_Interface.h"

#if POLRAITY== CATHODE

void SSD_SetNum(u8 num){
	u8 const SegmentArr[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	
	u8 r=num%10;
	u8 l=num/10;
	
	
	DIO_WritePin(COM2,LOW);
	DIO_WritePin(COM1,HIGH);
	SEGMENT_PORT=SegmentArr[r]<<1;
	
	_delay_ms(1);
	
	
	
	DIO_WritePin(COM2,HIGH);
	DIO_WritePin(COM1,LOW);
	
	SEGMENT_PORT=SegmentArr[l]<<1;
	_delay_ms(1);
	
	
}
#endif
