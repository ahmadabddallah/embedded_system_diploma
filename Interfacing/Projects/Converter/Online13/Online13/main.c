#include "MemMap.h" 
#include "StdTypes.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#define F_CPU 8000000
#include "util/delay.h"
#include "KEYPAD_Interface.h"
#include "UART.h"
#include "ADC_Interface.h"

#define BUTTON
int* volatile p;


/*typedef struct {
	u8 *str;
	void(*pf)(u8);
		
}command_type;

void ledOn(u8){
	
	
}
*/

int atoii(char *str){
	int num=0;
	
	int signeValue=1;
	for(int i=0;str[i];i++){
		if(str[i]=='-'){
			signeValue=0;
			continue;
		}
		num=num*10+(str[i]-'0');
		
	}
	if(signeValue==1){
	return num;
	}
	else{
		return (-num);
	}
	
}

u32 Binary_to_decimal(u8 *str){
	
	u32 result=0;
	u32 Power_of_two=1;
	char length=0;
	for(;str[length];length++);
	
	//10111
	for(s8 i=length-1;i>=0;i--){
		
		result+=((str[i]-'0')*Power_of_two);
		
		Power_of_two*=2;
		//return result;
	}

	return result;
	
}

void Upper_to_lower(u8 *str){
	for(u8 i=0;i<str[i];i++){
		if(str[i]>='A'&&str[i]<='Z'){
			str[i]-='A';
			str[i]+='a';
		}
	}
}


u32 Hex_to_decimal(u8 *str){
	u32 result=0;
	u32 power_of_16=1;
	
	//to handle upper case
	Upper_to_lower(str);
	
	// to read from last
	u8 length=0;
	for(;str[length];length++);
	
	
	//multiplay by *16 pow 0,1,2
	for (s8 i=length-1;i>=0;i--,power_of_16*=16){
		if(str[i]>='0'&&str[i]<='9'){
			result+=((str[i]-'0')*power_of_16);
		}
		
		else if(str[i]>='a'&&str[i]<='f'){
			switch(str[i]){
				case 'a':
				result+=10*power_of_16;
				break;
				case 'b':
				result+=11*power_of_16;
				break;
				case 'c':
				result+=12*power_of_16;
				break;
				case 'd':
				result+=13*power_of_16;
				break;
				case 'e':
				result+=14*power_of_16;
				break;
				case 'f':
				result+=15*power_of_16;
				break;
			}
			
		}
		
	}
	return result;

}
int main(void)
{
	DIO_Init();
	LCD_Init();
	KEYPAD_Init();

	
	
	
	LCD_GoTO(0,5);
	LCD_WriteString("Hello");
	LCD_GoTO(1,0);
	LCD_WriteString("convert from Ahmed");
	_delay_ms(1000);
	
	u8 key='C';
	LCD_Clear();
	
	u8 first_choice=0;
	u8 second_choice=0;
	u8 flag=0;
	u8 str_num[20]={0};
	u8 idx_str=0;	
	
	while(1){
		
		if(key=='C'){
		LCD_Clear();
		for(u8 i=0;i<20;i++){
			str_num[i]=0;
		}
		idx_str=0;
		first_choice=0;
		second_choice=0;
		flag=0;
		LCD_WriteString("convert from");
		LCD_GoTO(1,0);
		LCD_WriteString("1-D	2-B		3-H");
		}
		
		
		key=KEYPAD_GetKey();
		
		if(key>='1' &&key<='3' &&flag==0){
			first_choice=key;
			LCD_Clear();
			LCD_WriteString("Converted To ");
			
			switch(first_choice){
				case '1':
				LCD_WriteChar('D');
				break;
				case '2':
				LCD_WriteChar('B');
				break;
				case '3':
				LCD_WriteChar('H');
				break;
				
			}
			LCD_GoTO(1,0);
			LCD_WriteString("1-D	2-B		3-H");
			flag=1;
		
		}
		
		
		else if(key>='1' &&key<='3' &&flag==1){
			
			second_choice=key;
			LCD_Clear();
			
			switch(first_choice){
				case '1':
				LCD_WriteChar('D');
				break;
				case '2':
				LCD_WriteChar('B');
				break;
				case '3':
				LCD_WriteChar('H');
				break;
				
			}
			LCD_GoTO(1,0);
			switch(second_choice){
				case '1':
				LCD_WriteChar('D');
				break;
				case '2':
				LCD_WriteChar('B');
				break;
				case '3':
				LCD_WriteChar('H');
				break;
				
			}
			flag=2;
			LCD_GoTO(0,1);
			continue;
		}
		
		if(flag==2 ){
			
			if(key>='0'&&key<='9' || key>='a'&&key<='f'){
			LCD_WriteChar(key);
			str_num[idx_str++]=key;
			}
			else if(key=='='){
			str_num[idx_str]=0;
				flag=3;
			}
		}
		
		if(flag==3){

			LCD_GoTO(1,1);
			u8 num=0;
			switch(first_choice){
				case '1':
				num=atoii(str_num);
				break;
				case '2':
				num=Binary_to_decimal(str_num);
				break;
				case '3':
				num=Hex_to_decimal(str_num);
				break;
			}
			
			switch(second_choice){
				case '1':
				LCD_WriteNumber(num);
				flag=0;
				break;
				
				case '2':
				LCD_WriteBinary(num);
				flag=0;
				break;
				
				case '3':
				LCD_WriteHex(num);
				flag=0;
				break;
			}
			
		}
	}
	
}
	

