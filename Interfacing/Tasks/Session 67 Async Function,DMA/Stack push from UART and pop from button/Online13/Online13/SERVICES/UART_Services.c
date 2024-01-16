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
		UART_Send(str[i]);	
	}
}

void UART_ReceiveString(u8 *str){

	u8 i=0;
	str[0]=UART_Receive();
	//0x0d is Enter
		for(;str[i]!=0x0d;){
			i++;
			str[i]=UART_Receive();
			
		}
		str[i]=0;
	
}




void UART_SendNumber(u32 num){
	UART_Send((u8)num);
	UART_Send((u8)(num>>8));
	UART_Send((u8)(num>>16));
	UART_Send((u8)(num>>24));
	
}
u32 UART_ReceiveNumber(void){
	u32 num=0;
	
	u8 *ptr=&num;
	ptr[0]=UART_Receive();
	ptr[1]=UART_Receive();
	ptr[2]=UART_Receive();
	ptr[3]=UART_Receive();
	
	return num;
	
	
}


void UART_SendNumber_string(u32 num){
	
	u32 arr[30]={0};
	s8 idx_arr=0;
	while (num>0){
		arr[idx_arr++]=num%10+'0';
		num/=10;
		
	}
	for(s8 i=idx_arr-1;i>=0;i--){
		UART_Send(arr[i]);
		
	}
	
}


void UART_SendStringCheckSum(u8*str){	u8 i,l;	u16 sum=0;	/*number of bytes to send*/	for(l=0;str[l];l++)	{		sum+=str[l];	}	UART_Send(l);	for (i=0;str[i];i++)	{		UART_Send(str[i]);	}	UART_Send((u8)sum);	UART_Send((u8)(sum>>8));	}

u8 UART_ReceiveStringCheckSum(u8 *new_str){
	
	u8 length=0;
	length=UART_Receive();
	
	
	u16 current_sum=0;
	for(u8 i=0;i<length;i++){
		new_str[i]=UART_Receive();	
		current_sum+=new_str[i];
	}
	
	u8 sum1,sum2=0;
	sum1=UART_Receive();
	sum2=UART_Receive();
	u16 sum=sum1|((u16)sum2<<8);
	
	if(current_sum==sum){
		//true 
		return 1;
	}
	else{
		//false
		return 0;
	}
	
}

static u8 volatile *global_string=NULLPTR;



void UART_SendString_Async(u8 *str){
	static u8 idx=0;
	UART_Send(str[idx]);
	global_string=str;
	Set_TX_CallBack(send_async);
	TX_InterruptEnable();
	
}

void send_async(void){
	static u8 i=1;
	
	if(global_string[i]=='#'){
		TX_InterruptDisable();
		i=1;
		return;
	}
	
	UART_SendNoBlock(global_string[i]);
	i++;
	
}


/* UART SEND FRAME SOFTWARE	
u8 check_parity(u8 data){
	u8 counter=0;
	while(data>0){
		
		data&=(data-1);
		counter++;
	}
	return counter;
	
}

*/
#define EVEN	1
#define ODD		0

#define PARITY	EVEN

u16 UART_Frame(u8 data){
	
	u16 frame=0;
	
	//to set data
	frame=data;
	frame=frame<<1;
	
	/*to check and set parity*/
	u8 parity=0;
	u8 ones=0;
	while(data){
		
		ones+=data&1;
		data>>=1;
	}
	
	
	#if PARITY == EVEN
	
	if (parity%2!=0)
	{
		parity=1;
	}
	else{
		parity=0;
	}
	#else
	if (parity%2!=0)
	{
		parity=0;
	}
	else{
		parity=1;
	}
	#endif
	//to set parity
	if(parity==0){
		CLR_BIT(frame,9);
	}
	else{
		SET_BIT(frame,9);
	}
	
	
	//to set stop bit
	SET_BIT(frame,10);
	
	
	return frame;
	
}


void UART_sendFrame(u16 frame){
	
	for(u8 i=0;i<11;i++){
		DIO_WritePin(PINC0,READ_BIT(frame,i));
		_delay_us(104);
	}
	
}


