/*
 * RGB.c
 *
 * Created: 10/31/2023 12:15:53 AM
 *  Author: ahmed
 */ 

#include "RGB.h"

RGB_data RGB_ARR[9]={{"BLACK",0,0,0},
	{"WHITE",254,254,254},
	{"RED",254,0,0},
	{"GREEN",0,254,0},
	{"BLUE",0,0,254},
	{"RED",254,0,0},
	{"YELLOW",254,254,0},
	{"CYAN",0,254,254},
	{"Magenta",254,0,254}};



void RGB_Init(void){
	
	
	/* Wrooooooooooooooong it must initilaized in the main ---- don't invoke init iside init*
	TIMER0_Init(TIMER0_FASTPWM_MODE,TIMER0_SCALER_8);
	Timer1_Init(TIMER1_FASTPWM_ICR_TOP_MODE,TIMER1_SCALER_8);
	ICR1=255;
	
	TIMER0_OC0Mode(OC0_NON_INVERTING);
	Timer1_OCRA1Mode(OCRA_NON_INVERTING);
	Timer1_OCRB1Mode(OCRB_NON_INVERTING);
	*/
}

void RGB_SetColor(u8 *Color){
	
	for(u8 i=0;i<9;i++){
		if(check_string(Color,RGB_ARR[i].Name)==identical){
			
			RGB_CustomeColor(RGB_ARR[i].Red_degree,RGB_ARR[i].Green_degree,RGB_ARR[i].Blue_degree);
			return;
		}
	}
	// if color is not found set color to Black
	
	RGB_CustomeColor(RGB_ARR[0].Red_degree,RGB_ARR[0].Green_degree,RGB_ARR[0].Blue_degree);
	return;
	
}

void RGB_CustomeColor(u8 RED,u8 GREEN,u8 BLUE){
	
	
	OCR0=RED;
	OCR1A=GREEN;
	OCR1B=BLUE;
}