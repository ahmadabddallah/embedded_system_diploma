#include "MemMap.h" 
#include "StdTypes.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#define F_CPU 8000000
#include "util/delay.h"
#include "KEYPAD_Interface.h"
#include "ADC_Interface.h"
#include "Sensors_Interface.h"
#include "EX_Interrupt_Interface.h"
#include "Timers.h"
#include "EEPROM.h"
#include "EEPROM_Services.h"
#include "UART.h"
#include "UART_Services.h"
#include "SPI.h"
#include "Check_Password.h"
#include "ULTRASONIC.h"
#include "String.h"
#include "RGB.h"
#include "Stepper.h"
#include "Timers_Services.h"
#include "Servo.h"
#include "Button.h"
volatile u16 counter_ov=0;


int main(){
	
	
	DIO_Init();
	LCD_Init();
	//KEYPAD_Init();
	Button_Init();
	ADC_Init(VREF_AVCC,ADC_SCALER_64);
	Timer1_Init(TIMER1_FASTPWM_OCRA_TOP_MODE,TIMER1_SCALER_8);
	TIMER0_Init(TIMER0_PHASECORRECT_MODE,TIMER0_SCALER_8);
	TIMER0_OC0Mode(OC0_INVERTING);
	
	Servo_Init();
	LCD_GoTO(0,5);
	LCD_WriteString("Motors");
	LCD_GoTO(1,2);
	LCD_WriteString("Configuration");
	_delay_ms(500);
	LCD_Clear();
	LCD_GoTO(0,0);
	LCD_WriteString("1-Servo Motor");
	LCD_GoTO(1,0);
	LCD_WriteString("2-Stepper Motor");
	volatile u8 ky=No_Button;
	u8 servo_mode_flag=0,stepper_mode_flag=0,mood_choose_flag=0;
	
	u8 mood_phase_flag=0;

	while(1){
		ky=Buttons_read();
		if(ky!=No_Button&&mood_phase_flag==0){
			if(ky=='1' &&servo_mode_flag==0){
				servo_mode_flag=1;
				continue;
			}
			else if(ky=='2'&&stepper_mode_flag==0){
				stepper_mode_flag=1;
				continue;
			}
		}
		if(mood_phase_flag==0){
			if(servo_mode_flag==1){
				LCD_Clear();
				LCD_GoTO(0,0);
				LCD_WriteString("1: -90");
				LCD_GoTO(0,7);
				LCD_WriteString("2: 0");
				LCD_GoTO(1,0);
				LCD_WriteString("4: 90");;
				mood_phase_flag=1;
			}
			else if(stepper_mode_flag==1){
				LCD_Clear();
				LCD_GoTO(0,0);
				LCD_WriteString("1: -45");
				LCD_GoTO(0,7);
				LCD_WriteString("2: 45");
				LCD_GoTO(1,0);
				LCD_WriteString("4: Full Rotate");
				mood_phase_flag=1;
				
			}
		
		}
		else if(mood_choose_flag==0){
			if(servo_mode_flag==1){
				switch(ky){
					case '1':
					Servo_SetAngle(-90);
					break;
					case '2':
					Servo_SetAngle(0);
					break;
					case '4':
					Servo_SetAngle(90);
					break;
						 }			
				}
				
				else if(stepper_mode_flag==1){
					switch(ky){
						case '1':
						Stepper_UniPolar_ByAngle(-45);
						break;
						case '2':
						Stepper_UniPolar_ByAngle(45);
						break;
						case '4':
						Stepper_UniPolar_ByRotate(1);
						break;
							
					}		
				}
			}
			
		}
					
	
}

