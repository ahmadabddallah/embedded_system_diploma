/*
 * ULTRASONIC.c
 *
 * Created: 10/12/2023 11:19:22 PM
 *  Author: ahmed
 */ 


#include "ULTRASONIC.h"


static void ICU_UltraSonic(void);
static volatile u16 T1=0,T2=0,flag=0;
u16 UltraSonic_GetRead_cm(DIO_Pin_type pin){
	
	
	DIO_WritePin(pin,HIGH);
	_delay_us(10);
	DIO_WritePin(pin,LOW);
	
	/* Wrooooooooooooooong it must initilaized in the main ---- don't invoke init iside init**/
	/*Timer1_Init(TIMER1_NORMAL_MODE,TIMER1_SCALER_8);*/
	TCNT1=0;
	Timer1_ICU_SetCallBack(ICU_UltraSonic);
	Timer1_InputCaptureEdge(RISING);
	Timer1_ICU_InterruptEnable();
	while(flag<2);
	Timer1_ICU_InterruptDisable();
	flag=0;
	return ((T2-T1)/58);
	
	
}
static void ICU_UltraSonic(void){
	if(flag==0){
		T1=ICR1;
		flag=1;
		Timer1_InputCaptureEdge(FALLING);
	}
	else if(flag==1){
		T2=ICR1;
		flag=2;	
	}
	
}