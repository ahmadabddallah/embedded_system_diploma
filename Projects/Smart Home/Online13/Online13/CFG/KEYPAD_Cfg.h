/*
 * KEYPAD_Cfg.h
 *
 * Created: 24/06/2023 09:40:31 م
 *  Author: ahmed
 */ 


#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_
#include "DIO_Interface.h"

#define ROWS 4
#define COLS 4



#define FIRST_OUTPUT PINC0
#define FIRST_INPUT  PINC4


#if KEYPAD_PRG

const u8 KeysArr[ROWS][COLS]={ {'7','8','9','a'}
						,{'4','5','6','b'}
						,{'1','2','3','c'}
						,{'C','0','=','d'}};
						
#endif

#endif /* KEYPAD_CFG_H_ */