/*
 * Servo.c
 *
 * Created: 11/14/2023 1:21:37 AM
 *  Author: ahmed
 */ 

#include "Servo.h"


void Servo_Init(void){
	Timer1_OCRB1Mode(OCRA_NON_INVERTING);
	OCR1A=19999;
	
	
	OCR1B=999;
	
}

void Servo_SetAngle(s8 angle){
	
	OCR1B=((((s32)angle+90)*1000)/180)+999;
	
	
	
}