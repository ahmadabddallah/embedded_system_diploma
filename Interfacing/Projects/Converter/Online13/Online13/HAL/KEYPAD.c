/*
 * KEYPAD.c
 *
 * Created: 24/06/2023 09:39:54 م
 *  Author: ahmed
 */ 

#define KEYPAD_PRG 1

#include "StdTypes.h"
#include "DIO_Interface.h"
#include "KEYPAD_Interface.h"
#include "KEYPAD_Cfg.h"
#define F_CPU 8000000
#include "util/delay.h"

void KEYPAD_Init(void){
	
	for(u8 r=0;r<ROWS;r++)
	DIO_WritePin(FIRST_OUTPUT+r,HIGH);
	
		
}

u8 KEYPAD_GetKey(void){
	
	u8 r,c,key=NO_KEY;
	for(r=0;r<ROWS;r++){
		DIO_WritePin(FIRST_OUTPUT+r,LOW);
		for(c=0;c<COLS;c++){
			if(DIO_ReadPin(FIRST_INPUT+c)==LOW){
				key=KeysArr[r][c];
				_delay_ms(10);
				while(DIO_ReadPin(FIRST_INPUT+c)==LOW);
			}
		}
		DIO_WritePin(FIRST_OUTPUT+r,HIGH);
	}
	return key;
}