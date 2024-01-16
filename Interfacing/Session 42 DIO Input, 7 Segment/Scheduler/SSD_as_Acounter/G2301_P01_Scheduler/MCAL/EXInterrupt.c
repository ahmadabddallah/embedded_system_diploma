
#include "EXInterrupt.h"

static void(*Fptr_INT0)(void)=NULLPTR;
static void(*Fptr_INT1)(void)=NULLPTR;
static void(*Fptr_INT2)(void)=NULLPTR;

void EXI_Enable(ExInterruptSource_type interrupt)
{
	switch(interrupt)
	{
		case EX_INT0:
		SET_BIT(GICR,INT0);
		break;
		case EX_INT1:
		SET_BIT(GICR,INT1);
		break;
		case EX_INT2:
		SET_BIT(GICR,INT2);
		break;
	}
}
void EXI_Disable(ExInterruptSource_type interrupt)
{
	switch(interrupt)
	{
		case EX_INT0:
		CLEAR_BIT(GICR,INT0);
		break;
		case EX_INT1:
		CLEAR_BIT(GICR,INT1);
		break;
		case EX_INT2:
		CLEAR_BIT(GICR,INT2);
		break;
	}
}
void EXI_TriggerEdge(ExInterruptSource_type interrupt,TriggerEdge_type edge)
{
	switch(interrupt)
	{
		case EX_INT0:
		switch(edge)
		{
			case  LOW_LEVEL:
			CLEAR_BIT(MCUCR,ISC00);
			CLEAR_BIT(MCUCR,ISC01);
			break;
			case  ANY_LOGIC_CHANGE:
			SET_BIT(MCUCR,ISC00);
			CLEAR_BIT(MCUCR,ISC01);
			break;
			case  FALLING_EDGE:
			CLEAR_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
			case  RISING_EDGE:
			SET_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;	
		}
		break;
		case EX_INT1:
		switch(edge)
		{
			case  LOW_LEVEL:
			CLEAR_BIT(MCUCR,ISC10);
			CLEAR_BIT(MCUCR,ISC11);
			break;
			case  ANY_LOGIC_CHANGE:
			SET_BIT(MCUCR,ISC10);
			CLEAR_BIT(MCUCR,ISC11);
			break;
			case  FALLING_EDGE:
			CLEAR_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
			break;
			case  RISING_EDGE:
			SET_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
			break;
		}
		break;
		case EX_INT2:
		switch(edge)
		{
			case  LOW_LEVEL:
			
			break;
			case  ANY_LOGIC_CHANGE:
			
			break;
			case  FALLING_EDGE:
			CLEAR_BIT(MCUCSR,ISC2);
			
			break;
			case  RISING_EDGE:
			SET_BIT(MCUCSR,ISC2);
			break;
		}
		break;
	}
}
void EXI_SetCallBack(ExInterruptSource_type interrupt,void(*pf_local)(void))
{
	switch(interrupt)
	{
		case EX_INT0:
		Fptr_INT0=pf_local;
		break;
		case EX_INT1:
		Fptr_INT1=pf_local;
		break;
		case EX_INT2:
		Fptr_INT2=pf_local;
		break;
	}
	
}



ISR(INT0_vect)
{
	
	sei();
	
	if(Fptr_INT0!=NULLPTR)
	Fptr_INT0();	

}

ISR(INT1_vect,ISR_NOBLOCK)
{
	if(Fptr_INT1!=NULLPTR)
	{
		Fptr_INT1();
	}
	
}


ISR(INT2_vect)
{
	if(Fptr_INT2!=NULLPTR)
	{
		Fptr_INT2();
	}
}