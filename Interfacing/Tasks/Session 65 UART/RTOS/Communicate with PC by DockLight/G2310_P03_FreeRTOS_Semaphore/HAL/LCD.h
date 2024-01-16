

#ifndef LCD_H_
#define LCD_H_

#define  F_CPU 8000000UL
#include "StdTypes.h"
#include "DIO_Interface.h"
#include <util/delay.h>

#define   _4_BIT   0
#define  _8_BIT   1


/*********************************config***************************************/

#define LCD_MODE    _4_BIT

#define   RS           PINA1_PR
#define   RW           PINC1_PR
#define   EN           PINA2_PR

/*for 8 bit*/
#define   LCD_PORT     PA
/*for 4bit */
#define    D4    PINA3_PR
#define    D5    PINA4_PR
#define    D6    PINA5_PR
#define    D7    PINA6_PR


/*****************************************************************************/
void LCD_Init(void);
void LCD_WriteString(u8*str);
void LCD_CreateCharacter(u8 *Pattern,u8 Location);

void LCD_WriteChar(u8 ch);
void LCD_WriteString(u8*str);
void LCD_WriteNumber(s64 num);
void LCD_WriteNumberInBinary(u8 num);
void LCD_WriteNumberInBinary2(u8 num);
void LCD_GoTo(u8 Line, u8 x);
void LCD_Clear(void);
void LCD_WriteNumber_4D(u16 num);



void LCD_WriteNumber_GoTo(u8 line ,u8 x,s64 num);
#endif /* LCD_H_ */


