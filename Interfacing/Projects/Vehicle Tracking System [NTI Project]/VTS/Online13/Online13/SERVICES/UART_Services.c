/*
 * UART_Services.c
 *
 * Created: 30/06/2023 08:45:50 م
 *  Author: ahmed
 */ 

#include "UART_Services.h"


u8 volatile *global_string=NULLPTR;

u8 volatile *RX_String=NULLPTR;

static volatile idx_rxString=0;

void UART_SendString(u8 *str){
	u8 i;
	for(i=0;str[i];i++){
		
		UART_Send(str[i]);
		
	}
	
}

void UART_ReceiveString(u8 *str){

	u8 i=0;
	str[0]=UART_Receive();
	
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


void UART_SendStringCheckSum(u8*str){	u8 i,l;	u16 sum=0;	for(l=0;str[l];l++)	{		sum+=str[l];	}	UART_Send(l);	for (i=0;str[i];i++)	{		UART_Send(str[i]);	}	UART_Send((u8)sum);	UART_Send((u8)(sum>>8));	}

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

void string_async(void){
	static u8 i=1;
	
	if(global_string[i]==0){
		i=1;
		TX_InterruptDisable();
		return;
	}
	else{
			UART_SendNoBlock(global_string[i]);
			i++;
	}
	

	
}

void UART_SendString_Async(u8 *str){
	static u8 idx=0;
	UART_Send(str[idx]);
	global_string=str;
	Set_TX_CallBack(string_async);
	TX_InterruptEnable();
	
}
/*
void receive_gps(u8 *str);
/*
void UART_ReceiveString_Async(u8 *str){
	
	
	RX_String=str;
	//UART_Receive(RX_String[idx_rxString]);
	
	Set_RX_CallBack(receive_gps);
	RX_InterruptEnable();
	
	
	
}

void receive_gps(u8 *str){
	
	RX_String[idx_rxString++]=UART_ReceiveNoBlock();
	if(idx_rxString==1000){
		RX_InterruptDisable();
	}
	
	
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



u16 UART_Frame(u8 data){
	
	u16 frame=0;
	
	//to set data
	frame=data;
	frame=frame<<1;
	
	u8 parity=0;
	parity=check_parity(data);
	
	#if PARITY ==EVEN
	
	if (parity%2!=0)
	{
		parity=1;
	}
	else{
		
	}
	#else
	if (parity%2!=0)
	{
		
	}
	else{
		parity=1;
	}
	#endif
	//to set parity
	SET_BIT(frame,9);
	
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
*/

