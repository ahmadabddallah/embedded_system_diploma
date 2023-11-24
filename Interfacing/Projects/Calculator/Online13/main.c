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

int main(void)
{
	DIO_Init();
	
	
	DIO_Init();
	LCD_Init();
	KEYPAD_Init();
	u8 key=NO_KEY;
	
	char Num1_str[20];
	int idx_num1=0;
	char Num2_str[20];
	int idx_num2=0;
	char flag=0;
	char operation='C';
	
	int num1=0;
	int num2=0;
	int result=0;
	while(1){
		
		u8 key=KEYPAD_GetKey();
		if(key=='T'){
			continue;
		}
		if(key!='=')
		LCD_WriteChar(key);
		if(key>='0' &&key<='9' &&flag==0){
		Num1_str[idx_num1++]=key;
		 num1=atoii(Num1_str);
		}
		
		else if((key>='0' &&key<='9' &&flag==1)){
			Num2_str[idx_num2++]=key;
			num2=atoii(Num2_str);
		}
		
		else if(key =='C'){
			LCD_Clear();
			num1=0;
			num2=0;
			idx_num1=0;
			idx_num2=0;
			Num1_str[idx_num1]=0;
			Num2_str[idx_num2]=0;
			flag=0;
			
		}
		else if(key=='='){
			LCD_Clear();
			LCD_WriteString("ans");
			
			LCD_GoTO(1,0);
			switch(operation){
				case '+':
				result=num1+num2;
				LCD_WriteNumber(result);
				break;
				
				case '-':
				result=num1-num2;
				LCD_WriteNumber(result);
				break;
				
				case '*':
				result=num1*num2;
				LCD_WriteNumber(result);
				break;
				
				case'/':
				
				if(num2==0){
					LCD_WriteString("Can't division");
				}
				else{
					result=num1/num2;
				LCD_WriteNumber(result);
				if(num1%num2!=0){
					f32 rem=(f32)num1/num2;
					rem*=10;
					
					u8 res=rem;
					res%=10;
					LCD_WriteChar('.');
					LCD_WriteNumber(res);
				}
				}
				break;
				
			}
			
			num1=result;
			for(int i=0;i<20;i++){
				Num2_str[i]=0;
			}
			idx_num2=0;	
			LCD_GoTO(0,3);
		}
		else{
			operation=key;
			flag=1;
				
	}
	
	}
	
}
	

