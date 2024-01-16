#include "MemMap.h" 
#include "StdTypes.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#define F_CPU 8000000
#include "util/delay.h"

u8 counter=0;

int main(){
	
	DIO_Init();
	
	
	LCD_WriteString("LEDS");
	u16 pos=1;
	
	while(1){
		
		if(READ_BIT(PIND,0)==0){
								
				PORTB=pos;
				pos=pos<<1;
				_delay_ms(250);
					
		}
		
		else if(READ_BIT(PIND,1)==0){
				PORTB=pos;
				pos=pos>>1;
				_delay_ms(250);
		}
		if(pos>0x80){
			pos=1;
		}	
		else if(pos==0){
			pos=0x80;
		}
	}
		
}


