/*
 * Stepper.h
 *
 * Created: 11/13/2023 2:18:54 AM
 *  Author: ahmed
 */ 


#ifndef STEPPER_H_
#define STEPPER_H_

#include "DIO_Interface.h"
#include "Utils.h"
#define F_CPU 8000000
#include "util/delay.h"
#include "LCD_Interface.h"

#define COL1A	PINC0
#define COL1B	PINC1

#define COL2A	PINC2
#define COL2B	PINC3


#define STEPPER_STEP	1
#define STEPPER_CYCLE  512


#define STEPPER_DELAY 2


void Stepper_Bipolar_CW(void);


void Stepper_Bipolar_CCW(void);

void Stepper_UniPolar_CW(void);

void Stepper_UniPolar_ByAngle(s16 num);

void Stepper_UniPolar_ByRotate(u16 num);

void Stepper_UniPolar_CCW(void);




#endif /* STEPPER_H_ */