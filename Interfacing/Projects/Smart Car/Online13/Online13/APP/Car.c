/*
 * Car.c
 *
 * Created: 22/06/2023 07:58:22 م
 *  Author: ahmed
 */
 
#include "Car.h"

volatile u8 signal=0;

void Car_Init(void){
	
		
}

void CAR_Runnable(void){
	
	if (Detection_getStopFlag()==1){
		signal='5';
		
	}
	
	
	switch (signal){
	
	case '1':
	moveForward();
	break;
	case '2':
	moveBackward();
	break;
	case '3':
	moveRight();
	break;
	
	case'4':
	moveLeft();
	break;
	
	case '5':
	CAR_Stop();
	break;
	
	case '6':
	CAR_Speed(50);
	break;
	
	case '7':
	CAR_Speed(150);
	break;
	
	case '8':
	CAR_Speed(250);
	break;

	}
}



void moveForward(void){
	
	
	MOTOR_CCW(M1);
	MOTOR_CCW(M2);
	
}

void moveBackward(void){
	MOTOR_CW(M1);
	MOTOR_CW(M2);
	
}

void moveRight(void){
		MOTOR_CCW(M1);
		MOTOR_Stop(M2);
}
void moveLeft(void){
	
		MOTOR_CCW(M2);
		MOTOR_Stop(M1);
		
}

void CAR_Stop(void){
	
	MOTOR_Stop(M1);
		
	MOTOR_Stop(M2);
		
	
};

void CAR_Speed(u8 mode){
	
	switch(mode){
	case 50:
	MOTOR_Speed(M1,50);
	MOTOR_Speed(M1,50);
	break;
	case 150:
	MOTOR_Speed(M1,50);
	MOTOR_Speed(M1,50);
	break;
	
	case 250:
	MOTOR_Speed(M1,50);
	MOTOR_Speed(M1,50);
	break;
		
		
	}
	
}