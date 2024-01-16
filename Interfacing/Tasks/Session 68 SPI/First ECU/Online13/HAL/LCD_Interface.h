/*
 * LCD_Interface.h
 *
 * Created: 22/06/2023 01:03:33 ص
 *  Author: ahmed
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "StdTypes.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "LCD_Cfg.h"
#define F_CPU 8000000
#include "Util/delay.h"
#include "Utils.h"


void LCD_Init(void);


void LCD_Clear(void);

/****line 0:1 cell 0:15 *****/
void LCD_GoTO(u8 line,u8 cell);


void LCD_WriteString(u8 str[]);
void LCD_WriteNumber(s32 num);
void LCD_WriteChar(u8 ch); 
void LCD_WriteBinary(u8 num);
void LCD_WriteHex(u8 num);

void LCD_Write_4D(u16 num);


void LCDWriteStringGoto(u8 line,u8 cell,u8 * str);
void LCD_ClearPosition(u8 line,u8 cell,u8 noCells);


//void LCD_CustomChar(u8 address,u8* patten);


#endif /* LCD_INTERFACE_H_ */