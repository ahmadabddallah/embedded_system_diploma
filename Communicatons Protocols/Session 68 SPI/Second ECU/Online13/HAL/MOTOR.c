/*
 * MOTOR.c
 *
 * Created: 21/06/2023 09:05:53 م
 *  Author: ahmed
 */ 
#include "StdTypes.h"
#include "DIO_Interface.h"
#include "MOTOR_Cfg.h"
#include "MOTOR_Interface.h"
#include "Timers.h"

void MOTOR_Stop(MOTOR_type m){
	
	switch(m){
		
		case M1:
		DIO_WritePin(M1_IN1,LOW);
		DIO_WritePin(M1_IN2,LOW);
		break;
		case M2:
		DIO_WritePin(M2_IN1,LOW);
		DIO_WritePin(M2_IN2,LOW);
		break;
		
	}
}

void MOTOR_CW(MOTOR_type m){
	//motor start clock wise
	switch(m){
		
		case M1:
		DIO_WritePin(M1_IN1,LOW);
		DIO_WritePin(M1_IN2,HIGH);
		break;
		case M2:
		DIO_WritePin(M2_IN1,LOW);
		DIO_WritePin(M2_IN2,HIGH);
		break;
		
	}
}

void MOTOR_CCW(MOTOR_type m){
	switch(m){
		
		case M1:
		DIO_WritePin(M1_IN1,HIGH);
		DIO_WritePin(M1_IN2,LOW);
		break;
		case M2:
		DIO_WritePin(M2_IN1,HIGH);
		DIO_WritePin(M2_IN2,LOW);
		break;
		
	}	
}

void MOTOR_Speed(MOTOR_type m,u8 speed){
	
	if(speed>MOTOR_MAX_SPEED){
		speed=MOTOR_MAX_SPEED;
	}
	switch(m){
		case M1:
		M1_EN=speed;
		break;
		case M2:
		M2_EN=speed;
		break;
	}
	
} 