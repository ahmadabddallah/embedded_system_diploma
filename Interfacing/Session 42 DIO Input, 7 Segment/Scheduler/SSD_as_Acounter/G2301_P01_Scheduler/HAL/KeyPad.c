
#include "KeyPad.h"


static u8 keys_array[4][4]={{'7','8','9','/'},
{'4','5','6','*'},
{'1','2','3','-'},
{'c','0','=','+'}};

u8 KEYPAD_GetEntry(void)
{
	u8 r,c,key=DEAULT_KEY;
	DIO_WritePin(FIRST_OUT,HIGH);
	DIO_WritePin(FIRST_OUT+1,HIGH);
	DIO_WritePin(FIRST_OUT+2,HIGH);
	DIO_WritePin(FIRST_OUT+3,HIGH);
	for (r=0;r<ROWS;r++)
	{
		DIO_WritePin(FIRST_OUT+r,LOW);	
		for (c=0;c<COL;c++)
		{
			if (!DIO_ReadPin(FIRST_IN+c))
			{
				key=keys_array[r][c];
				while(!DIO_ReadPin(FIRST_IN+c));
			}
		}
		DIO_WritePin(FIRST_OUT+r,HIGH);	
	}
	return key;
}