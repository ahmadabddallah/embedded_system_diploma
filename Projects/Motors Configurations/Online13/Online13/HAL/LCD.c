/*
 * LCD.c
 *
 * Created: 22/06/2023 01:03:46 ص
 *  Author: ahmed
 */ 

#include "LCD_Interface.h"

#if LCD_MODE == _4_BIT

static void WriteIns(u8 ins){
	DIO_WritePin(RS,LOW);
	DIO_WritePin(D7,READ_BIT(ins,7));
	DIO_WritePin(D6,READ_BIT(ins,6));
	DIO_WritePin(D5,READ_BIT(ins,5));
	DIO_WritePin(D4,READ_BIT(ins,4));
	
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	
	DIO_WritePin(D7,READ_BIT(ins,3));
	DIO_WritePin(D6,READ_BIT(ins,2));
	DIO_WritePin(D5,READ_BIT(ins,1));
	DIO_WritePin(D4,READ_BIT(ins,0));
	
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	
}
static void WriteData(u8 data){
	DIO_WritePin(RS,HIGH);
	DIO_WritePin(D7,READ_BIT(data,7));
	DIO_WritePin(D6,READ_BIT(data,6));
	DIO_WritePin(D5,READ_BIT(data,5));
	DIO_WritePin(D4,READ_BIT(data,4));
	
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	
	DIO_WritePin(D7,READ_BIT(data,3));
	DIO_WritePin(D6,READ_BIT(data,2));
	DIO_WritePin(D5,READ_BIT(data,1));
	DIO_WritePin(D4,READ_BIT(data,0));
	
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	 
}

void LCD_Init(void){
	
	_delay_ms(50);
	WriteIns(0x02);
	WriteIns(0x28);
	WriteIns(0x0C);
	WriteIns(0x01);
	_delay_ms(1);
	WriteIns(0x06);
	
	
}

#else

static void WriteIns(u8 ins){
	DIO_WritePin(RS,LOW);
	DIO_WrtiePort(LCD_PORT,ins);//8 BIT 16
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	
} 
static void WriteData(u8 data){
	DIO_WritePin(RS,HIGH);
	DIO_WrtiePort(LCD_PORT,data);//8 BIT 16
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	
}

void LCD_Init(void){
	
	_delay_ms(50);
	
	WriteIns(0x38);
	WriteIns(0x0C);
	WriteIns(0x01);
	_delay_ms(1);
	WriteIns(0x06);
	
	
}

#endif



void LCD_WriteChar(u8 ch){
	WriteData(ch);
}


void LCD_GoTO(u8 line,u8 cell){
	if(line==0){
		WriteIns(0x80+cell);
	}
	else if(line==1){
		WriteIns(0x80+0x40+cell);
	}
}
void LCD_WriteString(u8 str[]){
	if(str[0]==0){
		WriteData('0');
		return ;
	}
	int i=0;
	for(;str[i]!='\0';i++){
		WriteData(str[i]);
		_delay_ms(100);
	}
	
}

void LCD_WriteNumber(s32 num){

	u8 str[20];
	s8 idx=0;
	if(num==0){
		LCD_WriteChar('0');
		return ;
	}
	if(num<0){
		LCD_WriteChar('-');
		num*=-1;
	}
	
	while(num>0){
		str[idx++]=num%10+'0';
		num/=10;
	}
	str[idx]=0;
	
	for(s8 i=idx-1;i>=0;i--){
		LCD_WriteChar(str[i]);
	}
	
}

void LCD_WriteBinary(u8 num){
	s8 i=7;
	for(;i>=0;i--){
		
		LCD_WriteChar((num>>i&1)?'1':'0');
		
	
	}
	
	
}
void LCD_WriteHex(u8 num){
	
	u8 str[20]={0};
	u8 idx=0;
	WriteData('0');
	WriteData('x');
	u8 digit=0;
	while(num>0){
		digit=num%16;
		if(digit<10){
			str[idx++]=(digit-0)+'0';
		}
		else{
			str[idx++]=(digit-10)+'a';
		}	
		num/=16;
	}
	
	for(u8 i=0,j=idx-1;i<idx/2;i++){
		u8 tmp=str[i];
		str[i]=str[j];
		str[j]=tmp;
	}
	LCD_WriteString(str);

}

void LCD_Write_4D(u16 num){
	u8 str[4];
	u8 i=0;
	//0 0 4 5 i
	for(;i<4;i++){
		str[i]='0';
	}
	i--;
	while(num>0){
		str[i--]=num%10+'0';
		num/=10;
	}
	i=0;
	for(;i<4;i++){
		LCD_WriteChar(str[i]);
	}	
}

void LCD_Clear(void){
	
	WriteIns(0x01);
	_delay_ms(1);
	
}

void LCDWriteStringGoto(u8 line,u8 cell,u8* str){
	LCD_GoTO(line,cell);
	LCD_WriteString(str);
}
void LCD_ClearPosition(u8 line,u8 cell,u8 noCells){
	LCD_GoTO(line,cell);
	for(u8 i=0;i<noCells;i++){
		LCD_WriteChar(' ');
	}
	
	
	
}