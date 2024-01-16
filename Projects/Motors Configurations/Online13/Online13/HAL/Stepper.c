/*
 * Stepper.c
 *
 * Created: 11/13/2023 2:19:07 AM
 *  Author: ahmed
 */ 



#include "Stepper.h"


void Stepper_Bipolar_CW(void){
	
	
	
	DIO_WritePin(COL1A,HIGH);
	DIO_WritePin(COL1B,LOW);
	DIO_WritePin(COL2A,LOW);
	DIO_WritePin(COL2B,LOW);
	_delay_ms(STEPPER_DELAY);
	
	DIO_WritePin(COL1A,LOW);
	DIO_WritePin(COL1B,LOW);
	DIO_WritePin(COL2A,HIGH);
	DIO_WritePin(COL2B,LOW);
	_delay_ms(STEPPER_DELAY);
	
	DIO_WritePin(COL1A,LOW);
	DIO_WritePin(COL1B,HIGH);
	DIO_WritePin(COL2A,LOW);
	DIO_WritePin(COL2B,LOW);
	_delay_ms(STEPPER_DELAY);
	
	DIO_WritePin(COL1A,LOW);
	DIO_WritePin(COL1B,LOW);
	DIO_WritePin(COL2A,LOW);
	DIO_WritePin(COL2B,HIGH);
	_delay_ms(STEPPER_DELAY);
	
	
}


void Stepper_Bipolar_CCW(void){
	
	DIO_WritePin(COL1A,LOW);
	DIO_WritePin(COL1B,LOW);
	DIO_WritePin(COL2A,LOW);
	DIO_WritePin(COL2B,HIGH);
	_delay_ms(STEPPER_DELAY);
	
	
	
	DIO_WritePin(COL1A,LOW);
	DIO_WritePin(COL1B,HIGH);
	DIO_WritePin(COL2A,LOW);
	DIO_WritePin(COL2B,LOW);
	_delay_ms(STEPPER_DELAY);
	
	
	DIO_WritePin(COL1A,LOW);
	DIO_WritePin(COL1B,LOW);
	DIO_WritePin(COL2A,HIGH);
	DIO_WritePin(COL2B,LOW);
	_delay_ms(STEPPER_DELAY);
	
	
	
	DIO_WritePin(COL1A,HIGH);
	DIO_WritePin(COL1B,LOW);
	DIO_WritePin(COL2A,LOW);
	DIO_WritePin(COL2B,LOW);
	_delay_ms(STEPPER_DELAY);
	
	
	
}



void Stepper_UniPolar_CCW(void){
	
	/*  FOR Proteus
	DIO_WritePin(COL1A,LOW);
	DIO_WritePin(COL1B,HIGH);
	DIO_WritePin(COL2A,LOW);
	DIO_WritePin(COL2B,LOW);
	_delay_ms(STEPPER_DELAY);
	
	
	
	DIO_WritePin(COL1A,LOW);
	DIO_WritePin(COL1B,LOW);
	DIO_WritePin(COL2A,LOW);
	DIO_WritePin(COL2B,HIGH);
	_delay_ms(STEPPER_DELAY);
	
	
	DIO_WritePin(COL1A,LOW);
	DIO_WritePin(COL1B,LOW);
	DIO_WritePin(COL2A,HIGH);
	DIO_WritePin(COL2B,LOW);
	_delay_ms(STEPPER_DELAY);
	
	
	DIO_WritePin(COL1A,HIGH);
	DIO_WritePin(COL1B,LOW);
	DIO_WritePin(COL2A,LOW);
	DIO_WritePin(COL2B,LOW);
	_delay_ms(STEPPER_DELAY);
	*/
	DIO_WritePin(COL1A,HIGH);
	DIO_WritePin(COL1B,LOW);
	DIO_WritePin(COL2A,LOW);
	DIO_WritePin(COL2B,LOW);
	_delay_ms(STEPPER_DELAY);
	
	DIO_WritePin(COL1A,LOW);
	DIO_WritePin(COL1B,HIGH);
	DIO_WritePin(COL2A,LOW);
	DIO_WritePin(COL2B,LOW);
	_delay_ms(STEPPER_DELAY);
	
	
	DIO_WritePin(COL1A,LOW);
	DIO_WritePin(COL1B,LOW);
	DIO_WritePin(COL2A,HIGH);
	DIO_WritePin(COL2B,LOW);
	_delay_ms(STEPPER_DELAY);
	
	
	DIO_WritePin(COL1A,LOW);
	DIO_WritePin(COL1B,LOW);
	DIO_WritePin(COL2A,LOW);
	DIO_WritePin(COL2B,HIGH);
	_delay_ms(STEPPER_DELAY);
	
	
}


void Stepper_UniPolar_CW(void){
	/*	FOR Proteus
	DIO_WritePin(COL1A,HIGH);
	DIO_WritePin(COL1B,LOW);
	DIO_WritePin(COL2A,LOW);
	DIO_WritePin(COL2B,LOW);
	_delay_ms(STEPPER_DELAY);
	
	
	DIO_WritePin(COL1A,LOW);
	DIO_WritePin(COL1B,LOW);
	DIO_WritePin(COL2A,HIGH);
	DIO_WritePin(COL2B,LOW);
	_delay_ms(STEPPER_DELAY);
	
	DIO_WritePin(COL1A,LOW);
	DIO_WritePin(COL1B,LOW);
	DIO_WritePin(COL2A,LOW);
	DIO_WritePin(COL2B,HIGH);
	_delay_ms(STEPPER_DELAY);
	
	DIO_WritePin(COL1A,LOW);
	DIO_WritePin(COL1B,HIGH);
	DIO_WritePin(COL2A,LOW);
	DIO_WritePin(COL2B,LOW);
	_delay_ms(STEPPER_DELAY);
	*/
	
	
		DIO_WritePin(COL1A,LOW);
		DIO_WritePin(COL1B,LOW);
		DIO_WritePin(COL2A,LOW);
		DIO_WritePin(COL2B,HIGH);
		_delay_ms(STEPPER_DELAY);
		
		
		DIO_WritePin(COL1A,LOW);
		DIO_WritePin(COL1B,LOW);
		DIO_WritePin(COL2A,HIGH);
		DIO_WritePin(COL2B,LOW);
		_delay_ms(STEPPER_DELAY);
		
		
		DIO_WritePin(COL1A,LOW);
		DIO_WritePin(COL1B,HIGH);
		DIO_WritePin(COL2A,LOW);
		DIO_WritePin(COL2B,LOW);
		_delay_ms(STEPPER_DELAY);
		
		
		DIO_WritePin(COL1A,HIGH);
		DIO_WritePin(COL1B,LOW);
		DIO_WritePin(COL2A,LOW);
		DIO_WritePin(COL2B,LOW);
		_delay_ms(STEPPER_DELAY);
		
}




void Stepper_UniPolar_ByAngle(s16 num){
	
	if(num>0){
	
		u32 no_of_steps;
		no_of_steps=(((u32)num*512)/(u32)360);
	
		for(u16 i=0;i<no_of_steps;i++){
			Stepper_UniPolar_CW();
			}
	
	}
	else if(num<0){
		
		u32 no_of_steps;
		num=num*(-1);
		no_of_steps=(((u32)num*512)/(u32)360);
		
		for(u16 i=0;i<no_of_steps;i++){
			Stepper_UniPolar_CCW();
		}
	}
	
}

void Stepper_UniPolar_ByRotate(u16 num){
	
		for(u16 j=0;j<num;j++){
			for(u16 i=0;i<512;i++){
				Stepper_UniPolar_CW();
			}
		}
	
	
}