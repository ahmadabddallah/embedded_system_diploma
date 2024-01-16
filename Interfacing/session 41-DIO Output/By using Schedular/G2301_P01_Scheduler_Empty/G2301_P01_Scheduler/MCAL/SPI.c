
#include "SPI.h"


void SPI_InitMaster(void)
{
	//master
	SET_BIT(SPCR,MSTR);
	//clock
	//polarity
	//phase
	
	
	//ENABLE
	SET_BIT(SPCR,SPE);
}
void SPI_InitSlave(void)
{
	//slave
	CLEAR_BIT(SPCR,MSTR);
	//phase
	//ENABLE
	SET_BIT(SPCR,SPE);
}

u8 SPI_SendReceive(u8 data)
{
	SPDR=data;
	while(!READ_BIT(SPSR,SPIF));
	return SPDR;
}

void SPI_SendNoblock(u8 data)
{
	SPDR=data;
}

u8 SPI_ReceiveNoblock(void)
{
	return SPDR;
}

u8 SPI_ReceivePeriodicChecking(u8 *pdata)
{
	if (READ_BIT(SPSR,SPIF))
	{
		*pdata=SPDR;
		return 1;
	}
	else
	return 0;
}