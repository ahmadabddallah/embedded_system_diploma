
#include "UART_Services.h"




void UART_SendInt(u32 num)
{
	UART_Send((u8)num);
	UART_Send((u8)(num>>8));
	UART_Send((u8)(num>>16));
	UART_Send((u8)(num>>24));
	//u8 *p=&num;
	//UART_Send(p[0]);
}
u32 UART_ReceiveInt(void)
{
	u8 Byte_1=UART_Receive();
	u8 Byte_2=UART_Receive();
	u8 Byte_3=UART_Receive();
	u8 Byte_4=UART_Receive();
	u32 num=Byte_1|((u32)Byte_2<<8)|((u32)Byte_3<<16)|((u32)Byte_4<<24);
	return num;
}


void UART_SendString(u8*str)
{
	u8 i;
	for (i=0;str[i];i++)
	{
		UART_Send(str[i]);
	}
	UART_Send('#');
}

void UART_ReceiveString(u8*str)
{
	u8 i=0;
	str[i]=UART_Receive();
	while(str[i]!='#')
	{
		i++;
		str[i]=UART_Receive();
	}
	str[i]=0;
}


void UART_SendString_CS(u8*str)
{
	u8 i=0;
	u16 sum=0;
	for (i=0;str[i];i++)
	{
		sum=sum+str[i];
	}
	UART_Send(i);
	for (i=0;str[i];i++)
	{
		UART_Send(str[i]);
	}
	UART_Send(sum);
	UART_Send(sum>>8);
	
}

u8 UART_ReceiveString_CS(u8*str)
{
	u8 i,lens,byte_1,byte_2;
	u16 sum_rece,sum=0;
	lens=UART_Receive();
	for (i=0;i<lens;i++)
	{
		str[i]=UART_Receive();
		sum=sum+str[i];
	}
	byte_1=UART_Receive();
	byte_2=UART_Receive();
	sum_rece=byte_1|(u16)byte_2<<8;
	if (sum==sum_rece)
	{
		return 1;
	}
	else 
	return 0;

}