
#include "DIO_Interface.h"

void DIO_InitPin(DIO_Pin_type pin ,DIO_PinStatus_type status)
{
	u8 pin_num;
	DIO_Port_type Port;
	
	Port=pin/8;
	pin_num=pin%8;
	
	switch (status)
	{
		case OUTPUT:
		switch (Port)
		{
			case PA_PR:
			SET_BIT(DDRA_PR,pin_num);
			break;
			case PB_PR:
			SET_BIT(DDRB_PR,pin_num);
			break;
			case PC_PR:
			SET_BIT(DDRC_PR,pin_num);
			break;
			case PD_PR:
			SET_BIT(DDRD_PR,pin_num);
			break;
		}
		break;
		case INLLUP:
		switch (Port)
		{
			case PA_PR:
			CLEAR_BIT(DDRA_PR,pin_num);
			SET_BIT(PORTA_PR,pin_num);
			break;
			case PB_PR:
			CLEAR_BIT(DDRB_PR,pin_num);
			SET_BIT(PORTB_PR,pin_num);
			break;
			case PC_PR:
			CLEAR_BIT(DDRC_PR,pin_num);
			SET_BIT(PORTC_PR,pin_num);
			break;
			case PD_PR:
			CLEAR_BIT(DDRD_PR,pin_num);
			SET_BIT(PORTD_PR,pin_num);
			break;
		}
		break;
		case INFREE:
		switch (Port)
		{
			case PA_PR:
			CLEAR_BIT(DDRA_PR,pin_num);
			CLEAR_BIT(PORTA_PR,pin_num);
			break;
			case PB_PR:
			CLEAR_BIT(DDRB_PR,pin_num);
			CLEAR_BIT(PORTB_PR,pin_num);
			break;
			case PC_PR:
			CLEAR_BIT(DDRC_PR,pin_num);
			CLEAR_BIT(PORTC_PR,pin_num);
			break;
			case PD_PR:
			CLEAR_BIT(DDRD_PR,pin_num);
			CLEAR_BIT(PORTD_PR,pin_num);
			break;
		}
		break;
	}
	
}
void DIO_Init(void)
{
	DIO_Pin_type i;
	for (i=PINA0_PR;i<TOTAL_PINS;i++)
	{
		DIO_InitPin(i,PinsStatusArray[i]);
	}
}

void DIO_WritePin(DIO_Pin_type Pin,DIO_Voltage_type Value)
	{
		u8 PinNum_InPort=Pin%8;
		DIO_Port_type Port=Pin/8;
		switch (Port)
		{
			case PA_PR:
			if (HIGH==Value)
			{
				SET_BIT(PORTA_PR,PinNum_InPort);
			}
			else
			{
				CLEAR_BIT(PORTA_PR,PinNum_InPort);
			}
			break;
			case PB_PR:
			if (HIGH==Value)
			{
				SET_BIT(PORTB_PR,PinNum_InPort);
			}
			else
			{
				CLEAR_BIT(PORTB_PR,PinNum_InPort);
			}
			break;
			case PC_PR:
			if (HIGH==Value)
			{
				SET_BIT(PORTC_PR,PinNum_InPort);
			}
			else
			{
				CLEAR_BIT(PORTC_PR,PinNum_InPort);
			}
			break;
			case PD_PR:
			if (HIGH==Value)
			{
				SET_BIT(PORTD_PR,PinNum_InPort);
			}
			else
			{
				CLEAR_BIT(PORTD_PR,PinNum_InPort);
			}
			break;
		}
	}

	DIO_Voltage_type DIO_ReadPin(DIO_Pin_type Pin)
	{
		u8 PinNum_InPort=Pin%8;
		DIO_Port_type Port=Pin/8;
		switch (Port)
		{
			case PA_PR:
			return READ_BIT(PINA_PR,PinNum_InPort);
			break;
			case PB_PR:
			return READ_BIT(PINB_PR,PinNum_InPort);
			break;
			case PC_PR:
			return READ_BIT(PINC_PR,PinNum_InPort);
			break;
			case PD_PR:
			return READ_BIT(PIND_PR,PinNum_InPort);
			break;
			default:
			return 0x00;
			break;
		}
	}
void DIO_TogglePin(DIO_Pin_type Pin)
{
	u8 PinNum=Pin%8;
	DIO_Port_type Port=Pin/8;
	
	switch(Port)
	{
		case PA_PR:
		TOGGLE_BIT(PORTA_PR,PinNum);
		break;
		case PB_PR:
		TOGGLE_BIT(PORTB_PR,PinNum);
		break;
		case PC_PR:
		TOGGLE_BIT(PORTC_PR,PinNum);

		break;
		case PD_PR:
		TOGGLE_BIT(PORTD_PR,PinNum);
		break;
		
	}
	
	
}

void DIO_WritePort(DIO_Port_type Port,u8 Value)
{
	switch (Port)
	{
		case PA_PR:
		PORTA_PR=Value;
		break;
		case PB_PR:
		PORTB_PR=Value;
		break;
		case PC_PR:
		PORTC_PR=Value;
		break;
		case PD_PR:
		PORTD_PR=Value;
		break;
	}
}
