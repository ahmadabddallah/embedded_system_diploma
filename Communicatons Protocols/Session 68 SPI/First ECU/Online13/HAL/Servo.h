/*
 * Servo.h
 *
 * Created: 11/14/2023 1:21:46 AM
 *  Author: ahmed
 */ 


#ifndef SERVO_H_
#define SERVO_H_

#include "DIO_Interface.h"
#include "Utils.h"
#include "StdTypes.h"
#include "Timers.h"


void Servo_Init(void);

void Servo_SetAngle(s8 angle);



#endif /* SERVO_H_ */