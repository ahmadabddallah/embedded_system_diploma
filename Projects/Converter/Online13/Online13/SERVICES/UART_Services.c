/*
 * UART_Services.c
 *
 * Created: 30/06/2023 08:45:50 م
 *  Author: ahmed
 */ 

#include "UART_Services.h"


void UART_SendString(u8 *str){
	
	u8 i;
	
	for(i=0;str[i];i++){
		
		_delay_ms(1);
		UART_Send(str[i]);
		
	}
	
	
}

void UART_ReceiveString(u8 *str){
	
	u8 i=0;
	str[i]=UART_Receive();
		
	for(;str[i]!='#';){
		i++;
		str[i]=UART_Receive();
		
	}
	str[i]=0;
	
}

void UART_SendNumber(u32 num){
	
	u8 *p=&num;
	/*using pointer*/
	UART_Send(p[0]);
	UART_Send(p[1]);
	UART_Send(p[2]);
	UART_Send(p[3]);
	
	UART_Send(num&0x000000ff);
	
	
	UART_Send((u8)num);
	UART_Send((u8)(num>>8));
	UART_Send((u8)(num>>16));
	UART_Send((u8)(num>>24));

	
}

u32 UART_ReceiveNumber(void){
	
	u32 num ;
	u8 *p=&num;
	p[0]=UART_Receive();
	p[1]=UART_Receive();
	p[2]=UART_Receive();
	p[3]=UART_Receive();
	
	u32 b1=UART_Receive();
	u32 b2=UART_Receive();
	u32 b3=UART_Receive();
	u32 b4=UART_Receive();
	
	num=b1|b2<<8|b3<<16|b4<<24;
	
	return num;
	
}


u8 checkEndian(void){
	u32 num=1;
	
	u8 *p=&num;
	if(*p==1){
		
		return 1;
	}
	else{
		return 0;
		
	}
	
}

u32 convertEndian(u32 num){
	u8 *p=&num;
	u8 temp;
	temp=p[0];
	p[0]=p[3];
	p[3]=temp;
	
	
	temp=p[2];
	p[2]=p[1];
	p[1]=temp;	
	//00000000 0000000 1111111   2222222
	num=(num>>24)|(num>>8)|(num<<8)|(num<<24);
	
	num=(num>>4)|(num<<4);
	
}
void convertEndian2(u32 *num){
	
	
}

void UART_SendStringCheckSum(u8 *str){
	
	u8 lens=0;
	u16 sum=0;
	for(lens=0;str[lens];lens++){
		
		sum=sum+str[lens];
	}
	
	UART_Send(lens);
	
	for(lens=0;str[lens];lens++){
		
		UART_Send(str[lens]);
	}
	
	UART_Send((u8)sum);
	UART_Send((u8)(sum>>8));
	
		
}

u8 UART_ReceiveStringCheckSum(u8 *str){
	
	u8 i,lens,b1,b2;
	u16 RecSum=0,ClcSum=0;
	lens=UART_Receive();
	
	for(i=0;i<lens;i++){
		
		str[i]=UART_Receive();
		ClcSum=ClcSum+str[i];
		
	}
	b1=UART_Receive();
	b2=UART_Receive();
	
	str[i]=0;
	RecSum=(u16)b1|(u16)(b2<<8); 
	
	
	if(RecSum==ClcSum){
		return 1;
	}
	else{
		return 0;
	}
	
	
	
}