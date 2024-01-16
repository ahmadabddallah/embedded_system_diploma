/*
 * Button.c
 *
 * Created: 11/15/2023 3:22:11 AM
 *  Author: ahmed
 */ 

#include "Button.h"


const u8 button_arr[]={'1','2','3','4'};


void Button_Init(void){
	//you can init all the pins to pull up here 
	
	
}


u8 Buttons_read(void){
	
	for(DIO_Pin_type pin=BUTTON1;pin<=BUTTON4;pin++){
			
		if(DIO_ReadPin(pin)==0){
			_delay_ms(250);
			return button_arr[pin-BUTTON1];
		}
		
	}
	return No_Button;
	
	
}