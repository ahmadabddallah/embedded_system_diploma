/*
 * ADC.c
 *
 * Created: 23/06/2023 08:30:46 م
 *  Author: ahmed
 */ 
#include "StdTypes.h"
#include "Utils.h"
#include "MemMap.h"
#include "ADC_Interface.h"




void ADC_Init(ADC_VoltRef_type vref,ADC_Prescaler_type prescaler){
	/*vref*/
	
	switch(vref)
	{
		case VREF_AREF:
		CLR_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		break;
		case VREF_AVCC:
		SET_BIT(ADMUX,REFS0);
		SET_BIT(ADMUX,REFS1);
		break;
		case VREF_256V:
		SET_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		break;	
	}
	
	 
	/*prescaller*/
	ADCSRA&=0xf8;
	prescaler&=0x07;
	ADCSRA|=prescaler;
	
	/* enable ADC*/
	SET_BIT(ADCSRA,ADEN);
	
	
} 

u16 ADC_Read(ADC_Channel_type channel){
	/*set channel mux*/
	ADMUX&=0xf8;
	ADMUX|=channel;
	/*start conversation*/
	SET_BIT(ADCSRA,ADSC);
	/*w8 adc finish*/
	while(READ_BIT(ADCSRA,ADSC));
	

	/*get read*/
	
	u16 res=ADCL;
	res=res|(ADCH<<8);
	
	
	return res;
	
}