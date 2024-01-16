
#include "ADC.h"
#include "LCD.h"
static u8 Read_flag=0;

void ADC_Init(ADC_Vref_type vref,ADC_Scaler_type scaler)
{
	//VREF
	switch(vref)
	{
		case VREF_AVCC:
		SET_BIT(ADMUX,REFS0);
		CLEAR_BIT(ADMUX,REFS1);
		break;
		case VREF_AREF:
		CLEAR_BIT(ADMUX,REFS0);
		CLEAR_BIT(ADMUX,REFS1);
		break;
		case VREF_256:
		SET_BIT(ADMUX,REFS0);
		SET_BIT(ADMUX,REFS1);
		break;	
	}
	//CLOCK
	ADCSRA=ADCSRA&0xF8;
	scaler=scaler&0X07;
	ADCSRA=ADCSRA|scaler;	
	
	//read adjust right
	CLEAR_BIT(ADMUX,ADLAR);
	
	//ENABLE
	SET_BIT(ADCSRA,ADEN);	
}


u16 ADC_Read(ADC_Channel_type ch)
{
	u8 x;
	
	//select channel
	ADMUX=ADMUX&0XE0;//0B11100000
	ADMUX=ADMUX|ch;
	//Start conversion
	SET_BIT(ADCSRA,ADSC);
	TCNT0=0;
	
	while(READ_BIT(ADCSRA,ADSC));//polling until adc end conversion
	x=TCNT0;
	LCD_GoTo(1,0);
	LCD_WriteNumber(x);
	
	//u16 adc=ADCL|((u16)ADCH<<8);
	return ADC;
	
}

void ADC_StartConversion(ADC_Channel_type ch)
{
	if (Read_flag==0)
	{
		//select channel
		ADMUX=ADMUX&0XE0;//0B11100000
		ADMUX=ADMUX|ch;
		//Start conversion
		SET_BIT(ADCSRA,ADSC);
		Read_flag=1;
	}
	
}

u16 ADC_GetRead(void)
{
	while(READ_BIT(ADCSRA,ADSC));//polling (busy wait)until adc end conversion
	//u16 adc=ADCL|((u16)ADCH<<8);
	Read_flag=0;
	return ADC;
	
}
u8 ADC_GetReadNoBlock(u16*pdata)
{
	if(READ_BIT(ADCSRA,ADSC)==0)//polling (periodic checking)until adc end conversion
	{
	//u16 adc=ADCL|((u16)ADCH<<8);
	*pdata= ADC;
	Read_flag=0;
	return 1;
	}
	else
	{
		return 0;
	}
	
}