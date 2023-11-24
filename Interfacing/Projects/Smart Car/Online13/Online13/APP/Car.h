/*
 * Car.h
 *
 * Created: 11/8/2023 2:33:30 AM
 *  Author: ahmed
 */ 


#ifndef CAR_H_
#define CAR_H_

#include "DIO_Interface.h"
#include "MOTOR_Interface.h"
#include "Detection.h"

extern volatile u8 signal;
void Car_Init(void);


void CAR_Runnable(void);

void moveForward(void);

void moveBackward(void);
void moveRight(void);

void moveLeft(void);

void CAR_Stop(void);

void CAR_Speed(u8 mode);


#endif /* CAR_H_ */