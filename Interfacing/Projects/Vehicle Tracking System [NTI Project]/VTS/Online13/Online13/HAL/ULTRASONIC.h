/*
 * ULTRASONIC.h
 *
 * Created: 10/12/2023 11:19:10 PM
 *  Author: ahmed
 */ 


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_
#include "StdTypes.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "Timers.h"



u16 UltraSonic_GetRead_cm(DIO_Pin_type pin);




#endif /* ULTRASONIC_H_ */