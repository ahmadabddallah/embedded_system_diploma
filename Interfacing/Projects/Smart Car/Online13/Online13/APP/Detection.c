/*
 * Detection.c
 *
 * Created: 22/06/2023 08:10:18 م
 *  Author: ahmed
 */ 


#include "Detection.h"

static volatile u16 distance=0;
void Detection_Runnable(void){
	distance=UltraSonic_GetRead_cm(PINB5);
	
	//ultrasonic needs 60 micro between every measurement
	_delay_ms(60);
}


u8 Detection_getStopFlag(void){
	
	if(distance>0 &&distance<15){
		return 1;
	}	
	else{
		return 0;
	}
	
}
