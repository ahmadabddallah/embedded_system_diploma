
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
			case PA:
			SET_BIT(DDRA,pin_num);
			break;
			case PB:
			SET_BIT(DDRB,pin_num);
			break;
			case PC:
			SET_BIT(DDRC,pin_num);
			break;
			case PD:
			SET_BIT(DDRD,pin_num);
			break;
		}
		break;
		case INLLUP:
		switch (Port)
		{
			case PA:
			CLEAR_BIT(DDRA,pin_num);
			SET_BIT(PORTA,pin_num);
			break;
			case PB:
			CLEAR_BIT(DDRB,pin_num);
			SET_BIT(PORTB,pin_num);
			break;
			case PC:
			CLEAR_BIT(DDRC,pin_num);
			SET_BIT(PORTC,pin_num);
			break;
			case PD:
			CLEAR_BIT(DDRD,pin_num);
			SET_BIT(PORTD,pin_num);
			break;
		}
		break;
		case INFREE:
		switch (Port)
		{
			case PA:
			CLEAR_BIT(DDRA,pin_num);
			CLEAR_BIT(PORTA,pin_num);
			break;
			case PB:
			CLEAR_BIT(DDRB,pin_num);
			CLEAR_BIT(PORTB,pin_num);
			break;
			case PC:
			CLEAR_BIT(DDRC,pin_num);
			CLEAR_BIT(PORTC,pin_num);
			break;
			case PD:
			CLEAR_BIT(DDRD,pin_num);
			CLEAR_BIT(PORTD,pin_num);
			break;
		}
		break;
	}
	
}
void DIO_Init(void)
{
	DIO_Pin_type i;
	for (i=PINA0;i<TOTAL_PINS;i++)
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
			case PA:
			if (HIGH==Value)
			{
				SET_BIT(PORTA,PinNum_InPort);
			}
			else
			{
				CLEAR_BIT(PORTA,PinNum_InPort);
			}
			break;
			case PB:
			if (HIGH==Value)
			{
				SET_BIT(PORTB,PinNum_InPort);
			}
			else
			{
				CLEAR_BIT(PORTB,PinNum_InPort);
			}
			break;
			case PC:
			if (HIGH==Value)
			{
				SET_BIT(PORTC,PinNum_InPort);
			}
			else
			{
				CLEAR_BIT(PORTC,PinNum_InPort);
			}
			break;
			case PD:
			if (HIGH==Value)
			{
				SET_BIT(PORTD,PinNum_InPort);
			}
			else
			{
				CLEAR_BIT(PORTD,PinNum_InPort);
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
			case PA:
			return READ_BIT(PINA,PinNum_InPort);
			break;
			case PB:
			return READ_BIT(PINB,PinNum_InPort);
			break;
			case PC:
			return READ_BIT(PINC,PinNum_InPort);
			break;
			case PD:
			return READ_BIT(PIND,PinNum_InPort);
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
		case PA:
		TOGGLE_BIT(PORTA,PinNum);
		break;
		case PB:
		TOGGLE_BIT(PORTB,PinNum);
		break;
		case PC:
		TOGGLE_BIT(PORTC,PinNum);

		break;
		case PD:
		TOGGLE_BIT(PORTD,PinNum);
		break;
		
	}
	
	
}

void DIO_WritePort(DIO_Port_type Port,u8 Value)
{
	switch (Port)
	{
		case PA:
		PORTA=Value;
		break;
		case PB:
		PORTB=Value;
		break;
		case PC:
		PORTC=Value;
		break;
		case PD:
		PORTD=Value;
		break;
	}
}