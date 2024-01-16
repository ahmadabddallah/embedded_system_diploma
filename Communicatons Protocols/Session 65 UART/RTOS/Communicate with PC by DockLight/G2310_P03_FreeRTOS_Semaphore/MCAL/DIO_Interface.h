

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"



typedef enum{
	PINA0_PR=0,
	PINA1_PR=1,
	PINA2_PR,
	PINA3_PR,
	PINA4_PR,
	PINA5_PR,
	PINA6_PR,
	PINA7_PR,
	PINB0_PR,
	PINB1_PR,
	PINB2_PR,
	PINB3_PR,
	PINB4_PR,
	PINB5_PR,
	PINB6_PR,
	PINB7_PR,
	PINC0_PR,
	PINC1_PR,
	PINC2_PR,
	PINC3_PR,
	PINC4_PR,
	PINC5_PR,
	PINC6_PR,
	PINC7_PR,
	PIND0_PR,
	PIND1_PR,
	PIND2_PR,
	PIND3_PR,
	PIND4_PR,
	PIND5_PR,
	PIND6_PR,
	PIND7_PR,
	TOTAL_PINS	
	}DIO_Pin_type;

typedef enum{
	LOW=0,
	HIGH
	}DIO_Voltage_type;
	
	typedef enum{
		OUTPUT,
		INFREE,
		INLLUP
		}DIO_PinStatus_type;

typedef enum{
	PA_PR=0,
	PB_PR,
	PC_PR,
	PD_PR
	}DIO_Port_type;


void DIO_InitPin(DIO_Pin_type pin ,DIO_PinStatus_type status);


void DIO_WritePin(DIO_Pin_type pin ,DIO_Voltage_type volt);
DIO_Voltage_type DIO_ReadPin(DIO_Pin_type pin );
void DIO_TogglePin(DIO_Pin_type pin);
void DIO_WritePort(DIO_Port_type port ,u8 data);
u8 DIO_ReadPort(DIO_Port_type port);

void DIO_Init(void);
extern const DIO_PinStatus_type PinsStatusArray[TOTAL_PINS];

#endif /* DIO_INTERFACE_H_ */
