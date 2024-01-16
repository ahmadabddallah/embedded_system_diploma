/*
 * GPS.c
 *
 * Created: 10/28/2023 6:44:44 PM
 *  Author: ahmed
 */ 

#include "GPS.h"

volatile  u8 filtered_data[500]={0};
volatile static u8 data[1000]={0};
volatile static u16 flag=0;


void GPS_RX(){
	static u8 i=0;
	data[i]=UART_ReceiveNoBlock();
	flag++;
	i++;
	if(flag>1800){
		for(u16 k=0;k<500;k++){
			filtered_data[k]=data[k];
		}
		RX_InterruptDisable();
		
	}
	if(i==999){
		i=0;
	}
}


void GPS_Init(void){
	
	Set_RX_CallBack(GPS_RX);
	
	RX_InterruptEnable();
	
	while(flag<1800)
	{
		LCD_GoTO(1,0);
		LCD_WriteNumber(flag);
		LCD_WriteString("     ");
	}
	flag=0;	
}

void updateGPS(void){
	
	Set_RX_CallBack(GPS_RX);
	
	RX_InterruptEnable();
	
}