/*
 * ADC_Interface.h
 *
 * Created: 23/06/2023 08:31:12 م
 *  Author: ahmed
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_


typedef enum{
	VREF_AREF,
	VREF_AVCC,
	VREF_256V

}ADC_VoltRef_type;

 
typedef enum{
	ADC_SCALER_2=1,
	ADC_SCALER_4,
	ADC_SCALER_8,
	ADC_SCALER_16,
	ADC_SCALER_32,
	ADC_SCALER_64,
	ADC_SCALER_128,
}ADC_Prescaler_type;



typedef enum{
	CH_0=0,
	CH_1,
	CH_2,
	CH_3,
	CH_4,
	CH_5,
	CH_6,
	CH_7
	
}ADC_Channel_type;


void ADC_Init(ADC_VoltRef_type,ADC_Prescaler_type prescaler);


u16 ADC_Read(ADC_Channel_type channel);

u16 ADC_ReadVolt (ADC_Channel_type CH);
void ADC_startConversion(ADC_Channel_type);
u16 ADC_GetRead(void);
u8 ADC_GetReadPerodic(u16 *pdata);
u16 ADC_GetReadNoblock(void);

#endif /* ADC_INTERFACE_H_ */