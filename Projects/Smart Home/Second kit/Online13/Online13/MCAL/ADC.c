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

static u8 ADC_BusyFlag;


void ADC_Init(ADC_VoltRef_type vref,ADC_Prescaler_type scaler){
	/*vref*/
	
	switch(vref)
	{
		case VREF_AREF:
		CLR_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		break;
		
		case VREF_AVCC:
		SET_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		break;
		
		case VREF_256V:
		SET_BIT(ADMUX,REFS0);
		SET_BIT(ADMUX,REFS1);
		break;	
	}
	
	 
	/*prescaller*/
	ADCSRA&=0xf8; 
	scaler&=0x07;
	ADCSRA=ADCSRA|scaler;
	
	/* enable ADC*/
	SET_BIT(ADCSRA,ADEN);
	
	
} 

u16 ADC_Read(ADC_Channel_type CH){
	/*set channel mux*/
	ADMUX&=0xE0;
	ADMUX|=CH;
	
	/*start conversation*/	
	SET_BIT(ADCSRA,ADSC);
	while(READ_BIT(ADSC,ADSC));
	 
	/*w8 adc finish*/
	//while(READ_BIT(ADCSRA,ADSC));
	

	/*get read*/
	
	/*u16 res=0;
	res=ADCL;
	res=res|(ADCH<<8);
	return res;
	*/
	
	/*if ADLE==1
	u16 adc=ADCL>>6;
	adc=adc|ADCH>>2;
	*/
	
	return ADC;
	
}

void ADC_startConversion(ADC_Channel_type CH){
	
	if(ADC_BusyFlag==0){
		/*set the channel to read from it*/
		ADMUX&=0xe0;
		ADMUX&=CH;
		
		/*start converstion*/
		SET_BIT(ADCSRA,ADSC);
	
	ADC_BusyFlag=1;	
	}
	
	

}

u16 ADC_GetRead(void){
	/*get read
	u16 result=0;
	result=ADCL;
	result|=ADCH<<8;
	return res;*/
	return ADC;
	
}

u8 ADC_GetReadPerodic(u16 *pdata){
	
	/* perodic check polling*/
	if(!READ_BIT(ADCSRA,ADSC)){
		*pdata=ADC;
		ADC_BusyFlag=0;
		return 1;
	}
	else{
		return 0;
		
	}
	
	
}


u16 ADC_VoltRead(ADC_Channel_type CH){

	u16 volt=0;
	
	u16 adc=ADC_Read(CH);
	
	volt=(adc*(u32)5000)/1023;
	return volt;
	
}

u16 ADC_GetReadNoblock(void){
	
	
	return ADC;
	
}