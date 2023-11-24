/*
 * Button.h
 *
 * Created: 11/15/2023 3:22:22 AM
 *  Author: ahmed
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_


#include "DIO_Interface.h"
#include "Utils.h"
#include "StdTypes.h"

#define No_Button 'T'

#define BUTTON1	PIND2
#define BUTTON2	PIND3
#define BUTTON3	PIND4
#define BUTTON4	PIND5


extern const u8 button_arr[];
void Button_Init(void);
u8 Buttons_read(void);


#endif /* BUTTON_H_ */