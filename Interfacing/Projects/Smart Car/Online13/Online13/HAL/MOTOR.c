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



void MOTOR_Init(void){
	TIMER0_Init(TIMER0_FASTPWM_MODE,TIMER0_SCALER_8);
	TIMER0_OC0Mode(OC0_NON_INVERTING);
	
	Timer1_Init(TIMER1_FASTPWM_ICR_TOP_MODE,TIMER1_SCALER_8);
	ICR1=256;
	Timer1_OCRA1Mode(OCRA_NON_INVERTING);
	
	
}

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
		
		case M3:
		DIO_WritePin(M3_IN1,LOW);
		DIO_WritePin(M3_IN2,LOW);
		break;
		
		case M4:
		DIO_WritePin(M4_IN1,LOW);
		DIO_WritePin(M4_IN2,LOW);
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
		
		case M3:
		DIO_WritePin(M3_IN1,LOW);
		DIO_WritePin(M3_IN2,HIGH);
		break;
		
		case M4:
		DIO_WritePin(M4_IN1,LOW);
		DIO_WritePin(M4_IN2,HIGH);
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
		
		case M3:
		DIO_WritePin(M3_IN1,HIGH);
		DIO_WritePin(M3_IN2,LOW);
		break;
		
		case M4:
		DIO_WritePin(M4_IN1,HIGH);
		DIO_WritePin(M4_IN2,LOW);
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
		case M3:
		M3_EN=speed;
		break;
		case M4:
		M4_EN=speed;
		break;
	}
	
} 